document.addEventListener("DOMContentLoaded", () => {
  const categoryLinks = document.querySelectorAll(".category-list a");
  const currentCategorySpan = document.getElementById("current-category");
  const categoryTitle = document.getElementById("category-title");
  const productCards = document.querySelectorAll(".product-card");

  let activeProduct = null;

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

  const overviewCards = document.querySelectorAll(".product-card[data-target-category]");
  overviewCards.forEach(card => {
    card.addEventListener("click", () => {
      const targetCategory = card.getAttribute("data-target-category");
      const matchingLink = document.querySelector(`.category-list a[data-category="${targetCategory}"]`);
      if (matchingLink) matchingLink.click();
    });
  });

  // Modal Elements
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

  function updateModalPrice() {
    if (!activeProduct) return;
    const qty = parseInt(modalQuantity.value, 10) || 1;
    const totalPrice = activeProduct.unitPrice * qty;
    modalPrice.textContent = `PHP ${totalPrice.toFixed(2)}`;
  }

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

  

  if (addToCartBtn) {
    addToCartBtn.addEventListener("click", () => {
      // 1. Check if user is logged in
      const currentUser = JSON.parse(localStorage.getItem('currentUser'));
      
      if (!currentUser) {
        alert("Please sign in to add items to your cart!");
        if (productModal) productModal.classList.remove("active");
        window.location.href = "Login.html";
        return;
      }

      if (!activeProduct) return;

      // 2. Add to cart if authenticated
      const qty = parseInt(modalQuantity.value, 10) || 1;
      let cart = JSON.parse(localStorage.getItem('cart')) || [];

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

  if (modalCloseBtn && productModal) {
    modalCloseBtn.addEventListener("click", () => productModal.classList.remove("active"));
    productModal.addEventListener("click", (e) => {
      if (e.target === productModal) productModal.classList.remove("active");
    });
  }

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