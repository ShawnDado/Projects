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

    // 3. Update the main heading to match what you clicked (e.g., "Brewed Coffee")
    if (categoryTitle) {
      categoryTitle.textContent = cleanName;
    }

    // Optional: Keep the breadcrumb fixed on "Drinks" or update it if you prefer
    // If you want breadcrumb to always say "Drinks", leave currentCategorySpan fixed in HTML.
    // If you want it to change too, uncomment the line below:
    // if (currentCategorySpan) currentCategorySpan.textContent = cleanName;

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