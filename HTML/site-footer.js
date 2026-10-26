class SiteFooter extends HTMLElement {
  // Called automatically by the browser when the element is inserted into the DOM[cite: 8].
  connectedCallback() {
    this.innerHTML = `
      <footer class="footer">
        <nav class="footer-nav">
          <a href="about.html">About Us</a>
          <a href="contacts.html">Contact Us</a>
        </nav>
        <div class="social">
          <div class="social-icons">
            <a href="#" aria-label="Social 1"><span class="icon-placeholder">⊗</span></a>
            <a href="#" aria-label="Social 2"><span class="icon-placeholder">⊗</span></a>
            <a href="#" aria-label="Social 3"><span class="icon-placeholder">⊗</span></a>
            <a href="#" aria-label="Social 4"><span class="icon-placeholder">⊗</span></a>
          </div>
        </div>
        <p class="copyright">&copy; 2026 Lavender Coffee Company. All rights reserved.</p>
      </footer>
    `;
  }
}

// Register custom HTML tag <site-footer>
customElements.define('site-footer', SiteFooter);