class SiteHeader extends HTMLElement {
  connectedCallback() {
    // allows the header to appear in all pages
    this.innerHTML = `
      <header class="navbar">
        <div class="nav-left">
          <a href="Home.html">
            <img src="logo.png" alt="Logo" class="logo">
          </a>
          <a href="menu.html" class="menu-btn" id="nav-menu">MENU</a>
        </div>
        <div class="nav-right">
          <a href="Login.html" class="sign-in-btn">Sign in</a>
        </div>
      </header>
    `;

    // Highlight menu button if the menu is active
    const currentUrl = window.location.href.toLowerCase();
    const menuBtn = this.querySelector('#nav-menu');

    if (menuBtn && currentUrl.includes('menu')) {
      menuBtn.classList.add('active');
    }
  }
}

customElements.define('site-header', SiteHeader);