document.addEventListener("DOMContentLoaded", () => {
  const categoryLinks = document.querySelectorAll(".category-list a");
  const currentCategorySpan = document.getElementById("current-category");
  const categoryTitle = document.getElementById("category-title");
  const productCards = document.querySelectorAll(".product-card");

  function switchCategory(targetCategory, categoryName, linkElement) {
    // 1. Highlight the active link in the sidebar
    categoryLinks.forEach(item => item.classList.remove("active"));
    if (linkElement) {
      linkElement.classList.add("active");
    }

    // 2. Clean up text (removes extra spaces/newlines)
    const cleanName = categoryName.trim();

    // 3. Update the main heading to match what you clicked
    if (currentCategorySpan) {
      currentCategorySpan.textContent = cleanName;
    }
    if (categoryTitle) {
      categoryTitle.textContent = cleanName;
    }

    // 4. Show/hide product cards matching the category
    productCards.forEach(card => {
      const cardCategory = card.getAttribute("data-category");
      if (cardCategory === targetCategory) {
        card.style.display = "block";
      } else {
        card.style.display = "none";
      }
    });
  }

  // Handle clicks on sidebar links
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

  // Handle clicks on overview cards with target categories
  const overviewCards = document.querySelectorAll(".product-card[data-target-category]");
  overviewCards.forEach(card => {
    card.addEventListener("click", () => {
      const targetCategory = card.getAttribute("data-target-category");
      const matchingLink = document.querySelector(`.category-list a[data-category="${targetCategory}"]`);
      if (matchingLink) {
        matchingLink.click();
      }
    });
  });

  // Handle product card modal popup
  productCards.forEach(card => {
    card.addEventListener("click", () => {
      const category = card.getAttribute("data-category");
      if (category === "drinks" || category === "foods") {
        return; // Skip modal for category overview cards
      }

      const imgElement = card.querySelector("img");
      const titleElement = card.querySelector(".product-title");
      const productDescription = card.getAttribute("data-description");

      const modalImg = document.getElementById("modalImg");
      const modalTitle = document.getElementById("modalTitle");
      const modalDescription = document.getElementById("modalDescription");
      const productModal = document.getElementById("productModal");

      if (imgElement && titleElement && modalImg && modalTitle && productModal) {
        modalImg.src = imgElement.src;
        modalImg.alt = imgElement.alt;
        modalTitle.textContent = titleElement.textContent;
        modalDescription.textContent = productDescription;
        productModal.classList.add("active");
      }
    });
  });

  // Close modal functionality
  const productModal = document.getElementById("productModal");
  const modalCloseBtn = document.getElementById("modalCloseBtn");

  if (modalCloseBtn && productModal) {
    modalCloseBtn.addEventListener("click", () => {
      productModal.classList.remove("active");
    });

    productModal.addEventListener("click", (e) => {
      if (e.target === productModal) {
        productModal.classList.remove("active");
      }
    });
  }

  // Handle page load
  function handleInitialHash() {
    const currentHash = window.location.hash;
    if (currentHash) {
      const matchingLink = document.querySelector(`.category-list a[href="${currentHash}"]`);
      if (matchingLink) {
        matchingLink.click();
      }
    } else {
      // Default to the first active link
      const defaultLink = document.querySelector(".category-list a.active");
      if (defaultLink) {
        defaultLink.click();
      }
    }
  }

  handleInitialHash();
});