document.addEventListener('DOMContentLoaded', function() {
    const cartShowButton = document.querySelector('.fa-cart-plus');
    const cartHideButton = document.querySelector('.fa-square-xmark');
    const cart = document.querySelector('.cart');
    const cartCount = document.querySelector('.cart-icon span');
    let itemCount = 0;
    cartShowButton.addEventListener("click", function() {
        cart.classList.add('show');
    });

    cartHideButton.addEventListener("click", function deletecart() {

        cart.classList.remove('show');
    });
});
const omg = document.querySelectorAll("button")
omg.forEach(function(button, index) {
    button.addEventListener("click", function(event) {
        var omgItem = event.target
        var product = omgItem.parentElement
        var producting = product.querySelector("img").src
        var productname = product.querySelector(".name").innerText
        var producprice = product.querySelector(".sp_gia").innerText

        addcart(producprice, producting, productname);
        updateCartCount();
    })
})

function addcart(producprice, producting, productname) {
    var addtr = document.createElement("tr")
    var cartitem = document.querySelectorAll("tbody tr")
    for (var i = 0; i < cartitem.length; i++) {
        var productT = document.querySelectorAll(".title")
        if (productT[i].innerHTML == productname) {
            alert("Sản phẩm đã có trong giỏ hàng")
            return
        }
    }
    var trcontent = '<tr><td style="display: flex;align-items: center; padding:"><img style="width: 70px;" src="' + producting + '" alt=""><span class="title">' + productname + '</span></td><td><p><span class="prices">' + producprice + '</span><sup>đ</sup></p></td><td><input style="width: 30px;outline: none;" type="number" value="1" min="1"></td><td style="cursor: pointer;"><span class="cart-delete">Xóa</span></td></tr>'
    addtr.innerHTML = trcontent
    var carttable = document.querySelector("tbody")
    carttable.append(addtr)
    carttotal()
    deletecart()
}

function carttotal() {
    var cartitem = document.querySelectorAll("tbody tr");
    var totalC = 0;

    for (var i = 0; i < cartitem.length; i++) {
        var inputvalue = parseInt(cartitem[i].querySelector("input").value);
        var producprice = cartitem[i].querySelector(".prices").innerHTML;
        var newsproductprice = producprice.split('.').join('');
        var itemTotal = parseInt(newsproductprice) * inputvalue;

        if (!isNaN(itemTotal)) {
            totalC += itemTotal;
        }
    }

    var carttotalA = document.querySelector(".price-total span");
    var cartprice = document.querySelector(".cart-icon span");
    carttotalA.innerHTML = totalC.toLocaleString('de-DE');
    cartprice.innerHTML = totalC.toLocaleString('de-DE') + '&#8363;';
    inputchange();
}

function updateCartCount() {
    let itemCount = 0;
    itemCount + 1; // Tăng số lượng sản phẩm trong giỏ hàng lên 1
    cartCount.innerText = itemCount;
    document.querySelector('.cart-icon span').innerText = itemCount;

}


function deleteCartItem() {
    // Xử lý xóa sản phẩm khỏi giỏ hàng
    // Sau khi xóa, cập nhật lại số sản phẩm và hiển thị trên biểu tượng giỏ hàng
    itemCount--; // Giảm số lượng sản phẩm trong giỏ hàng đi 1
    cartCount.innerText = itemCount;
    // Cập nhật số sản phẩm trên biểu tượng giỏ hàng
    document.querySelector('.cart-icon span').innerText = itemCount;
}


function deletecart() {
    var cartitem = document.querySelectorAll("tbody tr")
    for (var i = 0; i < cartitem.length; i++) {
        var productT = document.querySelectorAll(".cart-delete")
        productT[i].addEventListener("click", function(event) {
            var cartdelete = event.target
            var cartitemr = cartdelete.parentElement.parentElement
            cartitemr.remove();
            carttotal();
            deleteCartItem();
        })
    }
}

function inputchange() {
    var cartitem = document.querySelectorAll("tbody tr")
    for (var i = 0; i < cartitem.length; i++) {
        var inputvalue = cartitem[i].querySelector("input")
        inputvalue.addEventListener("change", function() {
            carttotal()
        })
    }
}

const cartomg = document.querySelector(".fa-square-xmark")
const cartshow = document.querySelector(".fa-cart-plus")
cartshow.addEventListener("click", function() {
    console.log(cartshow)
    document.querySelector(".cart").style.right = "0"
})
cartomg.addEventListener("click", function() {
    console.log(cartshow)
    document.querySelector(".cart").style.right = "-100%"
})
document.addEventListener('DOMContentLoaded', function() {
    const cartShowButton = document.querySelector('.fa-cart-plus');
    const cartHideButton = document.querySelector('.fa-square-xmark');
    const cart = document.querySelector('.cart');

    cartShowButton.addEventListener("click", function() {
        cart.classList.add('show');
    });

    cartHideButton.addEventListener("click", function deletecart() {

        cart.classList.remove('show');
    });
});
document.getElementById('payment-form').addEventListener('submit', function(event) {
    event.preventDefault(); // Ngăn chặn hành động mặc định của form

    // Lấy thông tin từ các trường input
    var name = document.getElementById('name').value;
    var phone = document.getElementById('phone').value;
    var address = document.getElementById('address').value;

    // Xử lý việc thanh toán ở đây (có thể gửi thông tin đến server để xử lý)

    // Hiển thị thông báo hoàn thành thanh toán
    alert('Cảm ơn bạn đã đặt hàng!');

    // Sau khi thanh toán thành công, có thể làm sạch giỏ hàng
    clearCart();
});

// Hàm để làm sạch giỏ hàng sau khi thanh toán thành công
function clearCart() {
    var cartTable = document.querySelector("tbody");
    cartTable.innerHTML = ''; // Xóa toàn bộ nội dung trong tbody

    // Đưa các số liệu về ban đầu
    totalC = 0;

    carttotal(); // Cập nhật tổng giá trị của giỏ hàng
}

// Gắn sự kiện click cho nút chốt đơn và gọi hàm xóa mặt hàng trong sự kiện này
const checkoutButton = document.querySelector('.checkout-button');
checkoutButton.addEventListener("click", function() {
    clearCart(); // Gọi hàm để xóa mặt hàng
    // Thêm bất kỳ logic nào khác cần thiết sau khi chốt đơn ở đây
});
const bankTransferOption = document.getElementById('bank-transfer');
const bankDetails = document.querySelector('.bank-details');

bankTransferOption.addEventListener('change', function() {
    if (bankTransferOption.checked) {
        bankDetails.style.display = 'block';
    } else {
        bankDetails.style.display = 'none';
    }
});

const checkoutButton1 = document.querySelector('.checkout-button');
checkoutButton1.addEventListener('click', function() {
    if (bankTransferOption.checked) {
        // Hiển thị thông báo cho người dùng về việc kiểm tra email để kiểm tra thanh toán
        alert('Vui lòng kiểm tra email để xác nhận thanh toán qua chuyển khoản.');
    } else {
        // Xử lý thanh toán bằng tiền mặt
        clearCart(); // Đặt lại giỏ hàng và tổng tiền
        // Thêm bất kỳ logic nào khác cần thiết sau khi chốt đơn ở đây
    }
});