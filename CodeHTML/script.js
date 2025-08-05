document.addEventListener('DOMContentLoaded', () => {
    // === CÀI ĐẶT ===
    const CORRECT_PASSWORD = "1234"; // <-- THAY MẬT KHẨU CỦA BẠN VÀO ĐÂY

    // === Lấy các phần tử từ HTML ===
    const passwordContainer = document.getElementById('password-container');
    const birthdayCard = document.getElementById('birthday-card');
    const passwordInput = document.getElementById('password-input');
    const submitBtn = document.getElementById('submit-btn');
    const errorMessage = document.getElementById('error-message');

    // === Xử lý sự kiện khi nhấn nút "Gửi" hoặc phím Enter ===
    submitBtn.addEventListener('click', checkPassword);
    passwordInput.addEventListener('keyup', (event) => {
        if (event.key === "Enter") {
            checkPassword();
        }
    });

    // === Hàm kiểm tra mật khẩu ===
    function checkPassword() {
        if (passwordInput.value === CORRECT_PASSWORD) {
            // Mật khẩu đúng, ẩn form và hiện thiệp
            passwordContainer.classList.add('hidden');
            birthdayCard.classList.remove('hidden');
        } else {
            // Mật khẩu sai, hiển thị thông báo lỗi
            errorMessage.classList.remove('hidden');
            passwordInput.value = ''; // Xóa nội dung đã nhập
            passwordInput.focus(); // Tập trung lại vào ô nhập
        }
    }
});