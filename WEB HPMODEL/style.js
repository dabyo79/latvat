document.addEventListener("DOMContentLoaded", function() {
    var toggleParent = document.getElementById('toggle-parent');
    var submenu = document.getElementById('submenu1');

    toggleParent.addEventListener("click", function() {
        toggleParent.classList.toggle('active'); // Thêm/xoá lớp active cho toggle-parent khi click
        submenu.classList.toggle('active'); // Thêm/xoá lớp active cho submenu khi click
    });
});



function openLoginForm() {
    document.getElementById("loginForm").style.display = "block";
}

function closeLoginForm() {
    document.getElementById("loginForm").style.display = "none";
}

function login() {
    // Xử lý đăng nhập ở đây
    alert("Đăng nhập thành công!");
}

function openRegistrationForm() {
    document.getElementById("registrationForm").style.display = "block";
}

function closeRegistrationForm() {
    document.getElementById("registrationForm").style.display = "none";
}

function register() {
    // Xử lý đăng ký ở đây
    alert("Đăng ký thành công!");
}




var texts = [
    "Tạo ra một nền tảng trực tuyến lành mạnh và sáng tạo, nơi mọi người có thể thỏa sức bay cao cùng đam mê sưu tập và tạo mô hình. Chúng tôi cam kết cung cấp những sản phẩm chất lượng cao và dịch vụ tận tâm, giúp khách hàng thỏa mãn niềm đam mê và khám phá tiềm năng sáng tạo của bản thân.",
    "Chúng tôi luôn đặt chất lượng lên hàng đầu, từ quá trình lựa chọn sản phẩm đến dịch vụ hậu mãi. Đội ngũ chuyên gia của chúng tôi chăm sóc từng sản phẩm một cách kỹ lưỡng, đảm bảo rằng mỗi món đồ mô hình được giao đến tay khách hàng đều là một tác phẩm nghệ thuật hoàn hảo.",
    "Chúng tôi luôn lắng nghe và hỗ trợ khách hàng một cách tận tình nhất. Đội ngũ chăm sóc khách hàng của chúng tôi luôn sẵn sàng trợ giúp và giải đáp mọi thắc mắc của quý khách hàng, từ việc lựa chọn sản phẩm đến quá trình sử dụng sau này.",
    "Qua nhiều năm hoạt động, chúng tôi tự hào khi nhận được sự tin tưởng và ủng hộ lớn từ phía khách hàng. Sự hài lòng của khách hàng là động lực lớn nhất để chúng tôi không ngừng phát triển và hoàn thiện hơn mỗi ngày."
];

var speeds = [10, 20, 30, 40]; // Tốc độ đánh máy (ms)
var indices = [-3, -2, -1, 0];

function typeWriter() {
    for (var i = 0; i < texts.length; i++) {
        var text = texts[i];
        var speed = speeds[i];
        var index = indices[i];
        if (index < text.length) {
            document.getElementById("text" + (i + 1)).innerHTML += text.charAt(index);
            indices[i]++;
            if (text.charAt(index) == '\n') {
                document.getElementById("text" + (i + 1)).innerHTML += "<br>";
            }
        }
    }
    setTimeout(typeWriter, Math.max(...speeds));
}

typeWriter();