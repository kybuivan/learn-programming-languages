# Input/output

Stream-based I/O (Input/Output) là một thư viện trong C++ được tổ chức dựa trên các thiết bị đầu vào/đầu ra trừu tượng. Những thiết bị trừu tượng này cho phép cùng một mã điều khiển xử lý đầu vào/đầu ra từ các tệp, luồng bộ nhớ hoặc các thiết bị tùy chỉnh thực hiện các hoạt động tùy ý (ví dụ: nén) trực tiếp.

Hầu hết các lớp trong thư viện này được tạo dưới dạng mẫu, cho phép áp dụng cho bất kỳ loại ký tự cơ bản nào. Cung cấp các typedef riêng biệt cho các loại ký tự cơ bản phổ biến nhất (`char` và `wchar_t`). Các lớp được tổ chức thành các cấu trúc phân cấp sau đây:

<img src="..\images\0\06\std-io-complete-inheritance.svg">

## Abstraction (Trừu tượng)
Được định nghĩa trong header `<ios>`.
- ios_base:
- basic_ios:
- basic_streambuf:
- basic_ostream:
- basic_istream:
- basic_iostream: