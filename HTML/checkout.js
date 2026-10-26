document.addEventListener('DOMContentLoaded', () => {
  // Retrieve current user session from localStorage
  const currentUser = JSON.parse(localStorage.getItem('currentUser'));
  const authRequiredMsg = document.getElementById('auth-required-message');
  const checkoutContent = document.getElementById('checkout-content');

  // Toggle authentication warning vs checkout layout using class toggling
  if (!currentUser) {
    if (authRequiredMsg) authRequiredMsg.classList.remove('u-hidden');
    if (checkoutContent) checkoutContent.classList.add('u-hidden');
    return;
  } else {
    if (authRequiredMsg) authRequiredMsg.classList.add('u-hidden');
    if (checkoutContent) checkoutContent.classList.remove('u-hidden');
  }

  // 2. Render cart items
  renderCart();

  // DOM element bindings for payment modal
  const btnProceedPayment = document.getElementById('btnProceedPayment');
  const paymentModal = document.getElementById('paymentModal');
  const paymentModalClose = document.getElementById('paymentModalClose');
  const confirmPayBtn = document.getElementById('confirmPayBtn');
  const errorMsg = document.getElementById('paymentErrorMsg');
  const subtotalDisplay = document.getElementById('modalSubtotalDisplay');
  const modalHeading = document.getElementById('modalHeading');
  const modalDynamicInputs = document.getElementById('modalDynamicInputs');

  let currentSubtotal = 0;

  // Function to calculate the current cart subtotal dynamically
  function getSubtotal() {
    const cart = JSON.parse(localStorage.getItem('cart')) || [];
    return cart.reduce((sum, item) => sum + (item.price * item.quantity), 0);
  }

  // Event listener for proceeding to payment modal
  if (btnProceedPayment && paymentModal) {
    btnProceedPayment.addEventListener('click', () => {
      const cart = JSON.parse(localStorage.getItem('cart')) || [];
      if (cart.length === 0) {
        alert('Your cart is empty!');
        return;
      }

      currentSubtotal = getSubtotal();
      if (subtotalDisplay) {
        subtotalDisplay.textContent = `Total Due: PHP ${currentSubtotal.toFixed(2)}`;
      }
      if (errorMsg) errorMsg.classList.add('u-hidden');

      // Check selected payment provider
      const selectedProviderInput = document.querySelector('input[name="wallet-provider"]:checked');
      const provider = selectedProviderInput ? selectedProviderInput.value : 'gcash';

      // Dynamically inject corresponding input fields based on payment provider
      if (modalDynamicInputs) {
        if (provider === 'gcash' || provider === 'paypal') {
          modalHeading.textContent = `Enter ${provider.toUpperCase()} Details`;
          modalDynamicInputs.innerHTML = `
            <input type="text" id="modalPhoneInput" class="modal-input-field" placeholder="Phone Number (11 digits, e.g., 09123456789)" maxlength="11" inputmode="numeric" required>
            <input type="number" id="depositAmountInput" class="modal-input-field" placeholder="Enter amount (PHP)" min="0" step="any" required>
          `;
        } else if (provider === 'credit-card') {
          modalHeading.textContent = 'Enter Card Details';
          modalDynamicInputs.innerHTML = `
            <input type="text" id="modalCardInput" class="modal-input-field" placeholder="Card Number" maxlength="16" inputmode="numeric" required>
            <input type="text" id="modalPhoneInput" class="modal-input-field" placeholder="Phone Number (11 digits)" maxlength="11" inputmode="numeric" required>
            <input type="number" id="depositAmountInput" class="modal-input-field" placeholder="Enter amount (PHP)" min="0" step="any" required>
          `;
        }
      }

      paymentModal.classList.add('active');
    });
  }

  // Close modal event handler
  if (paymentModalClose && paymentModal) {
    paymentModalClose.addEventListener('click', () => {
      paymentModal.classList.remove('active');
    });
  }

  // Confirmation and validation of payment transaction
  if (confirmPayBtn) {
    confirmPayBtn.addEventListener('click', () => {
      const depositInput = document.getElementById('depositAmountInput');
      const phoneInput = document.getElementById('modalPhoneInput');
      const cardInput = document.getElementById('modalCardInput');

      const depositVal = depositInput ? parseFloat(depositInput.value) : NaN;
      const phoneVal = phoneInput ? phoneInput.value.trim() : '';
      const cardVal = cardInput ? cardInput.value.trim() : '';

      const selectedProviderInput = document.querySelector('input[name="wallet-provider"]:checked');
      const provider = selectedProviderInput ? selectedProviderInput.value : 'gcash';

      // Validate 11-digit phone number using regex
      const phoneRegex = /^\d{11}$/;
      if (!phoneRegex.test(phoneVal)) {
        if (errorMsg) {
          errorMsg.textContent = 'Please enter a valid 11-digit card number.';
          errorMsg.classList.remove('u-hidden');
        }
        return;
      }

      // Validate credit card number if credit-card is selected
      if (provider === 'credit-card' && (!cardVal || cardVal.length < 16)) {
        if (errorMsg) {
          errorMsg.textContent = 'Please enter a valid 16-digit card number.';
          errorMsg.classList.remove('u-hidden');
        }
        return;
      }

      // Validate that tendered deposit covers the total due
      if (isNaN(depositVal) || depositVal < currentSubtotal) {
        if (errorMsg) {
          errorMsg.textContent = 'Payment invalid or insufficient amount. Try again.';
          errorMsg.classList.remove('u-hidden');
        }
        return;
      }

     // Capture cart data, transaction date, and payment details before clearing storage
      const purchasedCart = JSON.parse(localStorage.getItem('cart')) || [];
      const change = depositVal - currentSubtotal;
      const transactionDate = new Date().toLocaleString();

      let paymentMethodText = 'E-Wallet / Card';
      if (selectedProviderInput) {
        const parentLabel = selectedProviderInput.closest('.wallet-sub-option');
        if (parentLabel) {
          paymentMethodText = parentLabel.querySelector('span').textContent.trim();
        }
      }

      // Generate a random reference number
      let refNumber = '';
      if (provider === 'gcash' || provider === 'paypal') {
        const refLength = Math.floor(Math.random() * 6) + 8;
        for (let i = 0; i < refLength; i++) {
          refNumber += Math.floor(Math.random() * 10);
        }
      }

      // Close modal and clear cart storage
      paymentModal.classList.remove('active');
      localStorage.removeItem('cart');

      // Trigger header badge update event
      window.dispatchEvent(new Event('cartUpdated'));

      // Populate receipt DOM elements with transaction data
      const receiptDateEl = document.getElementById('receiptDate');
      const receiptPaymentMethodEl = document.getElementById('receiptPaymentMethod');
      const receiptPhoneEl = document.getElementById('receiptPhone');
      const receiptRefEl = document.getElementById('receiptRef');
      const receiptItemsEl = document.getElementById('receiptItemsList');
      const receiptTotalEl = document.getElementById('receiptTotalPaid');
      const receiptTenderedEl = document.getElementById('receiptAmountTendered');
      const receiptChangeEl = document.getElementById('receiptChange');

      if (receiptDateEl) receiptDateEl.textContent = `Date: ${transactionDate}`;
      if (receiptPaymentMethodEl) receiptPaymentMethodEl.textContent = `Payment Method: ${paymentMethodText}`;
      
      if (receiptPhoneEl) {
        receiptPhoneEl.textContent = `Phone Number: ${phoneVal}`;
        receiptPhoneEl.classList.remove('u-hidden');
      }

      if (receiptRefEl) {
        if (refNumber) {
          receiptRefEl.textContent = `Ref No: ${refNumber}`;
          receiptRefEl.classList.remove('u-hidden');
        } else {
          receiptRefEl.classList.add('u-hidden');
        }
      }

      if (receiptTotalEl) receiptTotalEl.textContent = `PHP ${currentSubtotal.toFixed(2)}`;
      if (receiptTenderedEl) receiptTenderedEl.textContent = `PHP ${depositVal.toFixed(2)}`;
      if (receiptChangeEl) receiptChangeEl.textContent = `PHP ${change.toFixed(2)}`;

      if (receiptItemsEl) {
        receiptItemsEl.innerHTML = purchasedCart.map(item => `
          <div class="receipt-item-row">
            <span>${item.title} (x${item.quantity})</span>
            <span>PHP ${(item.price * item.quantity).toFixed(2)}</span>
          </div>
        `).join('');
      }

      // Switch screen view from checkout layout to success screen
      const checkoutContentEl = document.getElementById('checkout-content');
      if (checkoutContentEl) checkoutContentEl.classList.add('u-hidden');
      const successScreen = document.getElementById('payment-success-content');
      if (successScreen) {
        successScreen.classList.remove('u-hidden');
      }
    });
  }
});

 //Renders the cart summary list and calculates subtotal
  function renderCart() {
  const cart = JSON.parse(localStorage.getItem('cart')) || [];
  const container = document.getElementById('cartItemsList');
  const subtotalEl = document.getElementById('cartSubtotal');

  if (!container || !subtotalEl) return;

  if (cart.length === 0) {
    container.innerHTML = `
      <div class="cart-item-row">
        <div class="item-left">
          <span class="item-name empty-cart-text">Your cart is empty</span>
        </div>
        <div>PHP 0.00</div>
      </div>
    `;
    subtotalEl.textContent = 'PHP 0.00';
    return;
  }

  let subtotal = 0;
  container.innerHTML = cart.map((item, index) => {
    const itemTotal = item.price * item.quantity;
    subtotal += itemTotal;

    return `
      <div class="cart-item-row cart-item-spacing">
        <div class="item-left">
          <span class="item-name">${item.title}</span>
          <span class="item-unit-price">PHP ${item.price.toFixed(2)} each</span>
          <div class="item-qty-wrap item-qty-wrap-margin">
            <button type="button" class="qty-btn-sm" onclick="changeQty(${index}, -1)">-</button>
            <span class="qty-number-bold">${item.quantity}</span>
            <button type="button" class="qty-btn-sm" onclick="changeQty(${index}, 1)">+</button>
          </div>
        </div>
        <div class="item-total-bold">PHP ${itemTotal.toFixed(2)}</div>
      </div>
    `;
  }).join('');

  subtotalEl.textContent = `PHP ${subtotal.toFixed(2)}`;
}

//Global helper function to adjust item quantities in the cart
window.changeQty = function(index, delta) {
  let cart = JSON.parse(localStorage.getItem('cart')) || [];
  if (cart[index]) {
    cart[index].quantity += delta;
    if (cart[index].quantity <= 0) {
      cart.splice(index, 1);
    }
    localStorage.setItem('cart', JSON.stringify(cart));
    renderCart();

    window.dispatchEvent(new Event('cartUpdated'));
  }
};