document.addEventListener("DOMContentLoaded", () => {
  const categoryLinks = document.querySelectorAll(".category-list a");
  const currentCategorySpan = document.getElementById("current-category");
  const categoryTitle = document.getElementById("category-title");
  const productCards = document.querySelectorAll(".product-card");

  let activeProduct = null;
  
  // Function to filter and switch categories in the product display grid
  function switchCategory(targetCategory, categoryName, linkElement) {
    categoryLinks.forEach(item => item.classList.remove("active"));
    if (linkElement) linkElement.classList.add("active");

    const cleanName = categoryName.trim();
    if (currentCategorySpan) currentCategorySpan.textContent = cleanName;
    if (categoryTitle) categoryTitle.textContent = cleanName;

    productCards.forEach(card => {
      const cardCategory = card.getAttribute("data-category");
      if (cardCategory === targetCategory) {
        card.style.display = "block";
      } else {
        card.style.display = "none";
      }
    });
  }
  
  // Attach event listeners to sidebar category links
  categoryLinks.forEach(link => {
    link.addEventListener("click", (e) => {
      e.preventDefault();
      const targetCategory = link.getAttribute("data-category");
      const categoryName = link.textContent;
      const hash = link.getAttribute("href");

      if (hash && hash.startsWith("#")) {
        window.location.hash = hash;
      }
      switchCategory(targetCategory, categoryName, link);
    });
  });

  // Handle overview cards to jump directly to categories
  const overviewCards = document.querySelectorAll(".product-card[data-target-category]");
  overviewCards.forEach(card => {
    card.addEventListener("click", () => {
      const targetCategory = card.getAttribute("data-target-category");
      const matchingLink = document.querySelector(`.category-list a[data-category="${targetCategory}"]`);
      if (matchingLink) matchingLink.click();
    });
  });

  // Modal element references
  const productModal = document.getElementById("productModal");
  const modalCloseBtn = document.getElementById("modalCloseBtn");
  const modalImg = document.getElementById("modalImg");
  const modalTitle = document.getElementById("modalTitle");
  const modalDescription = document.getElementById("modalDescription");
  const modalPrice = document.getElementById("modalPrice");
  const modalQuantity = document.getElementById("modalQuantity");
  const qtyMinus = document.getElementById("qtyMinus");
  const qtyPlus = document.getElementById("qtyPlus");
  const addToCartBtn = document.getElementById("addToCartBtn");

  // Dynamically update total price in the product modal based on quantity
  function updateModalPrice() {
    if (!activeProduct) return;
    const qty = parseInt(modalQuantity.value, 10) || 1;
    const totalPrice = activeProduct.unitPrice * qty;
    modalPrice.textContent = `PHP ${totalPrice.toFixed(2)}`;
  }

  // Open modal when clicking individual product cards
  productCards.forEach(card => {
    card.addEventListener("click", () => {
      const category = card.getAttribute("data-category");
      if (category === "drinks" || category === "foods") return; // Skip overview cards

      const id = card.getAttribute("data-id");
      const title = card.querySelector(".product-title").textContent;
      const description = card.getAttribute("data-description");
      const unitPrice = parseFloat(card.getAttribute("data-price") || "0");
      const imgSrc = card.querySelector("img").src;

      activeProduct = { id, title, description, unitPrice, imgSrc };

      if (modalImg) modalImg.src = imgSrc;
      if (modalTitle) modalTitle.textContent = title;
      if (modalDescription) modalDescription.textContent = description;
      if (modalQuantity) modalQuantity.value = 1;

      updateModalPrice();
      if (productModal) productModal.classList.add("active");
    });
  });

  // Handle modal quantity increment/decrement buttons
  if (qtyMinus && qtyPlus && modalQuantity) {
    qtyMinus.addEventListener("click", () => {
      let val = parseInt(modalQuantity.value, 10) || 1;
      if (val > 1) {
        modalQuantity.value = val - 1;
        updateModalPrice();
      }
    });

    qtyPlus.addEventListener("click", () => {
      let val = parseInt(modalQuantity.value, 10) || 1;
      modalQuantity.value = val + 1;
      updateModalPrice();
    });
  }

  // Handle adding product to cart with login check
  if (addToCartBtn) {
    addToCartBtn.addEventListener("click", () => {
      const currentUser = JSON.parse(localStorage.getItem('currentUser'));
      
      if (!currentUser) {
        alert("Please sign in to add items to your cart!");
        if (productModal) productModal.classList.remove("active");
        window.location.href = "Login.html";
        return;
      }

      if (!activeProduct) return;

      const qty = parseInt(modalQuantity.value, 10) || 1;
      let cart = JSON.parse(localStorage.getItem('cart')) || [];

      // Check if item already exists in cart and update quantity accordingly
      const existingIndex = cart.findIndex(item => item.id === activeProduct.id);
      if (existingIndex > -1) {
        cart[existingIndex].quantity += qty;
      } else {
        cart.push({
          id: activeProduct.id,
          title: activeProduct.title,
          price: activeProduct.unitPrice,
          quantity: qty,
          image: activeProduct.imgSrc
        });
      }

      localStorage.setItem('cart', JSON.stringify(cart));
      window.dispatchEvent(new Event('cartUpdated'));

      if (productModal) productModal.classList.remove("active");
    });
  }

  // Close modal event listeners
  if (modalCloseBtn && productModal) {
    modalCloseBtn.addEventListener("click", () => productModal.classList.remove("active"));
    productModal.addEventListener("click", (e) => {
      if (e.target === productModal) productModal.classList.remove("active");
    });
  }

  // Handle URL hash routing on initial page load
  function handleInitialHash() {
    const currentHash = window.location.hash;
    if (currentHash) {
      const matchingLink = document.querySelector(`.category-list a[href="${currentHash}"]`);
      if (matchingLink) matchingLink.click();
    } else {
      const defaultLink = document.querySelector(".category-list a.active");
      if (defaultLink) defaultLink.click();
    }
  }

  handleInitialHash();
});