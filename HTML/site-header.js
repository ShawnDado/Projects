class SiteHeader extends HTMLElement {
  connectedCallback() {
    // checks if user is logged in
    const currentUser = JSON.parse(localStorage.getItem('currentUser'));
    
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
          <a href="${currentUser ? '#' : 'Login.html'}" class="sign-in-btn" id="auth-btn">
            ${currentUser ? 'Log out' : 'Sign in'}
          </a>
        </div>
      </header>
    `;

    // Highlight menu button if the menu is active
    const currentUrl = window.location.href.toLowerCase();
    const menuBtn = this.querySelector('#nav-menu');
    if (menuBtn && currentUrl.includes('menu')) {
      menuBtn.classList.add('active');
    }

    // 3. Attach Logout functionality
    if (currentUser) {
      const authBtn = this.querySelector('#auth-btn');
      authBtn.addEventListener('click', (e) => {
        e.preventDefault();
        
        // Remove current user session
        localStorage.removeItem('currentUser');
        
        // Refresh the page to update the UI back to "Sign in"
        window.location.href = 'Login.html';
      });
    }
  }
}

customElements.define('site-header', SiteHeader);