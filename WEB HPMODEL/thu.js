document.addEventListener('DOMContentLoaded', function() {
    const viewDetailButtons = document.querySelectorAll('.batman');

    viewDetailButtons.forEach(function(button) {
        button.addEventListener('click', function() {
            const product = this.closest('.sp');
            const productName = product.querySelector('.name').innerText;
            const productPrice = product.querySelector('.sp_gia').innerText;
            const productSalePrice = product.querySelector('.sp_gg').innerText;
            const productDetails = {
                name: productName,
                gia: productPrice,
                gia_giam: productSalePrice,
                kich_co: 'L', // Thêm các thông tin khác như kích cỡ, chất liệu, thời gian bảo hành ở đây
                chat_lieu: 'Nhựa',
                bao_hanh: '12 tháng'
            };

            alert('Tên sản phẩm: ' + productDetails.name + '\nGiá gốc: ' + productDetails.gia + '\nGiá khuyến mãi: ' + productDetails.gia_giam + '\nKích cỡ: ' + productDetails.kich_co + '\nChất liệu: ' + productDetails.chat_lieu + '\nThời gian bảo hành: ' + productDetails.bao_hanh);
        });
    });
});