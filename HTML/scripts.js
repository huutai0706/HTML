document.addEventListener('DOMContentLoaded', () => {

    // --- CÁC PHẦN TỬ GIAO DIỆN ---
    const trollButton = document.getElementById('troll-button');
    const fakeCloseButton = document.getElementById('fake-close-button');
    const container = document.querySelector('.container');
    const fakeCursor = document.getElementById('fake-cursor');
    const fakeError = document.getElementById('fake-error');

    // --- TROLL CHUNG CHO CẢ HAI NỀN TẢNG ---

    // 1. Ngăn đóng tab dễ dàng
    window.addEventListener('beforeunload', (event) => {
        event.preventDefault();
        event.returnValue = "Bạn có chắc muốn bỏ cuộc không?";
        return "Bạn có chắc muốn bỏ cuộc không?";
    });

    // 2. Nút đóng giả yêu cầu mật khẩu
    fakeCloseButton.addEventListener('click', () => {
        const correctPassword = "123";
        const userInput = prompt("Muốn thoát à? Nhập mật khẩu xem nào:");
        if (userInput === correctPassword) {
            alert("Đúng rồi! Nhưng tôi vẫn không cho bạn đi đâu. Haha!");
        } else {
            alert("Sai mật khẩu! Mắc bẫy rồi nhé!");
        }
    });


    // --- HÀM KIỂM TRA THIẾT BỊ ---
    function isMobile() {
        return /Mobi|Android/i.test(navigator.userAgent);
    }


    // --- LOGIC PHÂN CHIA THEO THIẾT BỊ ---

    if (isMobile()) {
        // ===================================
        // === CÁC TRÒ TROLL CHO ĐIỆN THOẠI ===
        // ===================================
        
        // Ẩn con trỏ giả trên điện thoại
        if(fakeCursor) fakeCursor.style.display = 'none';

        // 1. Troll Rung
        trollButton.addEventListener('click', () => {
            if (window.navigator && window.navigator.vibrate) {
                navigator.vibrate([500, 200, 500, 200, 1000]);
            }
        });

        // 2. Troll Màn hình lắc lư
        window.addEventListener('deviceorientation', (event) => {
            container.style.transform = `rotateX(${event.beta/2}deg) rotateY(${event.gamma/2}deg)`;
        });

        // 3. Troll Cuộn ngược
        let lastY = 0;
        document.body.addEventListener('touchmove', (e) => e.preventDefault(), { passive: false });
        document.body.addEventListener('touchstart', (e) => { lastY = e.touches[0].clientY; }, { passive: false });
        document.body.addEventListener('touchend', (e) => {
            const currentY = e.changedTouches[0].clientY;
            window.scrollBy(0, -(currentY - lastY));
        });

    } else {
        // =================================
        // === CÁC TRÒ TROLL CHO MÁY TÍNH ===
        // =================================
        
        // 1. Troll Nút bỏ chạy
        trollButton.addEventListener('mouseover', () => {
            const newTop = Math.random() * (window.innerHeight - trollButton.offsetHeight);
            const newLeft = Math.random() * (window.innerWidth - trollButton.offsetWidth);
            trollButton.style.top = `${newTop}px`;
            trollButton.style.left = `${newLeft}px`;
        });
        
        // 2. Troll Con trỏ chuột giả
        document.addEventListener('mousemove', (e) => {
            fakeCursor.style.left = e.clientX + 'px';
            fakeCursor.style.top = e.clientY + 'px';
        });
        
        // 3. Troll Hộp thoại lỗi giả
        // Kích hoạt khi bấm nút troll chính
        trollButton.addEventListener('click', () => {
            fakeError.style.display = 'block';
        });
        document.querySelector('.close-error-btn').addEventListener('click', () => {
            fakeError.style.display = 'none';
        });
        document.querySelector('.error-ok-btn').addEventListener('click', () => {
            alert('Bạn nghĩ bấm OK là xong à? Không đâu!');
            fakeError.style.display = 'none';
        });
    }
});