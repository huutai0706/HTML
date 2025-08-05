document.addEventListener('DOMContentLoaded', () => {
    // === CÀI ĐẶT ===
    const CORRECT_PASSWORD = "1234"; // <-- THAY MẬT KHẨU CỦA BẠN VÀO ĐÂY
    const RECIPIENT_NAME = "Người ấy của bạn"; // <-- THAY TÊN NGƯỜI NHẬN VÀO ĐÂY

    // === Lấy các phần tử từ HTML ===
    const passwordContainer = document.getElementById('password-container');
    const birthdayCard = document.getElementById('birthday-card');
    const galleryPage = document.getElementById('gallery-page'); // New gallery page
    const passwordInput = document.getElementById('password-input');
    const submitBtn = document.getElementById('submit-btn');
    const errorMessage = document.getElementById('error-message');
    const recipientNameElement = document.getElementById('recipient-name'); // Element for recipient name
    const viewGalleryBtn = document.getElementById('view-gallery-btn'); // Button to view gallery
    const backToCardBtn = document.getElementById('back-to-card-btn'); // Button to go back to card

    // Set recipient name
    recipientNameElement.textContent = RECIPIENT_NAME;

    // === Xử lý sự kiện khi nhấn nút "Gửi" hoặc phím Enter ===
    submitBtn.addEventListener('click', checkPassword);
    passwordInput.addEventListener('keyup', (event) => {
        if (event.key === "Enter") {
            checkPassword();
        }
    });

    // === Xử lý sự kiện cho nút xem ảnh và quay lại ===
    viewGalleryBtn.addEventListener('click', () => {
        birthdayCard.classList.add('hidden');
        galleryPage.classList.remove('hidden');
        galleryPage.classList.add('visible'); // Add visible class for transition
    });

    backToCardBtn.addEventListener('click', () => {
        galleryPage.classList.remove('visible'); // Remove visible class for transition
        galleryPage.classList.add('hidden');
        birthdayCard.classList.remove('hidden');
    });

    // === Hàm kiểm tra mật khẩu ===
    function checkPassword() {
        if (passwordInput.value === CORRECT_PASSWORD) {
            // Mật khẩu đúng, ẩn form và hiện thiệp
            passwordContainer.classList.add('hidden');
            birthdayCard.classList.remove('hidden');
            // Sau khi thiệp xuất hiện, hiển thị nút xem ảnh sau một khoảng thời gian
            setTimeout(() => {
                viewGalleryBtn.classList.remove('hidden');
            }, 4000); // Adjust delay as needed for animations to complete
        } else {
            // Mật khẩu sai, hiển thị thông báo lỗi
            errorMessage.classList.remove('hidden');
            passwordInput.value = ''; // Xóa nội dung đã nhập
            passwordInput.focus(); // Tập trung lại vào ô nhập
            // Hide error message after a few seconds
            setTimeout(() => {
                errorMessage.classList.add('hidden');
            }, 3000);
        }
    }
});
