document.addEventListener('DOMContentLoaded', () => {
    // ---- PHẦN CŨ VẪN GIỮ NGUYÊN ----
    const trollMessage = "Bạn có chắc chắn muốn rời khỏi không? Nếu rời đi, bạn sẽ bỏ lỡ một điều bất ngờ lớn!";

    window.addEventListener('beforeunload', (event) => {
        event.preventDefault();
        event.returnValue = trollMessage;
        return trollMessage;
    });

    const trollButton = document.getElementById('troll-button');
    trollButton.addEventListener('click', () => {
        for (let i = 0; i < 5; i++) {
            alert("Haha, bạn nghĩ bạn có thể thoát sao? Thử lại lần nữa đi!");
        }
    });

    // ---- PHẦN LOGIC MỚI CHO NÚT ĐÓNG GIẢ ----
    
    // 🔒 Đặt mật khẩu của bạn ở đây
    const correctPassword = "123"; 

    const fakeCloseButton = document.getElementById('fake-close-button');

    fakeCloseButton.addEventListener('click', () => {
        // Hiển thị hộp thoại yêu cầu người dùng nhập văn bản
        const userInput = prompt("Để đóng tab này, vui lòng nhập mật khẩu:");

        // Kiểm tra xem người dùng có nhấn "Cancel" hay không
        if (userInput === null) {
            alert("Bạn đã hủy bỏ. Không thể đóng tab!");
            return;
        }

        // Kiểm tra mật khẩu
        if (userInput === correctPassword) {
            // ✅ Mật khẩu đúng
            alert("Mật khẩu chính xác! Tab sẽ được đóng.");
            
            // Lệnh này cố gắng đóng tab. 
            // Lưu ý: Nó chỉ hoạt động nếu trang được mở bằng một đoạn script khác (ví dụ: window.open()).
            // Nếu người dùng tự mở tab, lệnh này có thể không hoạt động do chính sách của trình duyệt.
            window.close();

        } else {
            // ❌ Mật khẩu sai
            alert("Mật khẩu không chính xác! Hãy thử lại nếu dám.");
        }
    });
});