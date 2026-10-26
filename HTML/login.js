document.addEventListener('DOMContentLoaded', () => {
  const loginForm = document.querySelector('.form-container form');

  if (loginForm) {
    loginForm.addEventListener('submit', (e) => {
      e.preventDefault();

      // Retrieve input values from email and password fields
      const email = loginForm.querySelector('input[type="email"]').value.trim();
      const password = loginForm.querySelector('input[type="password"]').value;

      // Fetch stored users array from localStorage or initialize an empty one
      const storedUsers = JSON.parse(localStorage.getItem('users')) || [];

      // Check if user already exists in storage
      const existingUser = storedUsers.find((user) => user.email === email);

      if (existingUser) {
        // Authenticate existing user by checking password match
        if (existingUser.password === password) {
          localStorage.setItem('currentUser', JSON.stringify(existingUser));
        } else {
          alert('Incorrect password!');
          return;
        }
      } else {
        // Store new credentials if user does not exist
        const newUser = { email, password };
        storedUsers.push(newUser);
        localStorage.setItem('users', JSON.stringify(storedUsers));
        localStorage.setItem('currentUser', JSON.stringify(newUser));
      }

      // Redirect to homepage after successful authentication/registration
      window.location.href = 'index.html';

    });
  }
});