class SiteHeader extends HTMLElement {
  connectedCallback() {
    this.innerHTML = `
      <header class="navbar">
        <div class="nav-left">
          <img src="logo.png" alt="Logo" class="logo">
          <a href="menu.html" class="menu-btn">Menu</a>
        </div>
        <div class="nav-right">
          <a href="login.html" class="sign-in-btn">Sign in</a>
        </div>
      </header>
    `;
  }
}

customElements.define('site-header', SiteHeader);