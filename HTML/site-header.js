class SiteHeader extends HTMLElement {
  connectedCallback() {
    this.render();

    // Listen for cart updates across the site in real-time
    window.addEventListener('cartUpdated', () => {
      this.updateBadgeCount();
    });

    // Listen for storage events across tabs
    window.addEventListener('storage', (e) => {
      if (e.key === 'cart') {
        this.updateBadgeCount();
      }
    });
  }

  // Dynamically update the cart badge count indicator
  updateBadgeCount() {
    const cart = JSON.parse(localStorage.getItem('cart')) || [];
    const totalItems = cart.reduce((sum, item) => sum + item.quantity, 0);
    const badge = this.querySelector('#cartBadge');
    if (badge) {
      badge.textContent = totalItems;
    }
  }

  render() {
    // Check user login session and cart total items
    const currentUser = JSON.parse(localStorage.getItem('currentUser'));
    const cart = JSON.parse(localStorage.getItem('cart')) || [];
    const totalItems = cart.reduce((sum, item) => sum + item.quantity, 0);
    
    // Render HTML layout template for header
    this.innerHTML = `
      <header class="navbar">
        <div class="nav-left">
          <a href="index.html">
            <img src="images/logo.png" alt="Logo" class="logo">
          </a>
          <a href="menu.html" class="menu-btn" id="nav-menu">MENU</a>
        </div>
        <div class="nav-right">
          <a href="checkout.html" class="cart-btn" id="nav-cart" title="View Cart">
            <svg class="cart-icon" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" width="24" height="24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
              <circle cx="9" cy="21" r="1"></circle>
              <circle cx="20" cy="21" r="1"></circle>
              <path d="M1 1h4l2.68 13.39a2 2 0 0 0 2 1.61h9.72a2 2 0 0 0 2-1.61L23 6H6"></path>
            </svg>
            <span class="cart-badge" id="cartBadge">${totalItems}</span>
          </a>
          <a href="${currentUser ? '#' : 'Login.html'}" class="sign-in-btn" id="auth-btn">
            ${currentUser ? 'Log out' : 'Sign in'}
          </a>
        </div>
      </header>
    `;

    // Highlight the menu button if the current page is the menu
    const currentUrl = window.location.href.toLowerCase();
    const menuBtn = this.querySelector('#nav-menu');
    if (menuBtn && currentUrl.includes('menu')) {
      menuBtn.classList.add('active');
    }

    // Attach Logout functionality if a user session exists
    if (currentUser) {
      const authBtn = this.querySelector('#auth-btn');
      authBtn.addEventListener('click', (e) => {
        e.preventDefault();
        localStorage.removeItem('currentUser');
        window.location.href = 'Login.html';
      });
    }
  }
}

customElements.define('site-header', SiteHeader);