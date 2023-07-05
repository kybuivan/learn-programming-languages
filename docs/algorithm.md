# Algorithm

Thư viện `algorithm` cung cấp các hàm để thực hiện nhiều mục đích khác nhau (ví dụ: tìm kiếm, sắp xếp, đếm, biến đổi) trên một tập hợp các phần tử. Lưu ý rằng khoảng của tập hợp các phần tử được xác định bởi hai chỉ số [`first`, `last`), trong đó `last` được sử dụng để tham chiếu đến phần tử _tiếp theo_ sau phần tử cuối cùng trong tập hợp mà chúng ta muốn thao tác hoặc sửa đổi.

## Các thao tác không làm thay đổi nội dung của chuỗi

Được định nghĩa trong header `<algorithm>`. Các hàm này thường được sử dụng để tìm kiếm, duyệt, đếm hoặc so sánh các phần tử trong chuỗi.

- all_of, any_of, none_of(C++11): kiểm tra xem một điều kiện (predicate) có `đúng` với tất cả, bất kỳ hoặc không có phần tử nào trong một phạm vi (range) cho trước
- for_each: áp dụng một hàm (function) cho một phạm vi (range) các phần tử
- for_each_n(C++17): áp dụng một đối tượng hàm (function object) cho n phần tử đầu tiên của một chuỗi
- count, count_if: trả về số lượng phần tử thỏa mãn tiêu chí cụ thể
- mismatch: trả về vị trí không khớp đầu tiên của hai chuỗi
- find, find_if, find_if_not(C++11): trả về phần phần tử đầu tiên thỏa mãn tiêu chí cụ thể
- find_end: tìm chuỗi phần tử cuối cùng trong một phạm vi cụ thể
- find_first_of: tìm kiếm bất kỳ một trong các phần tử trong một tập hợp
- adjacent_find: tìm hai mục kế tiếp đầu tiên mà bằng nhau (hoặc thoả mãn một giả định đã cho)
- search: tìm kiếm một phạm vi các phần tử
- search_n: tìm kiếm một phạm vi cho một số lượng liên tiếp các bản sao của một phần tử

## Sửa đổi các hoạt động trên chuỗi
Được định nghĩa trong header `<algorithm>`.
- copy, copy_if(C++11): sao chép một phạm vi các phần tử thoả mãn một điều kiện cho trước đến vị trí mới
- copy_n(C++11): sao chép một số lượng phần tử từ một phạm vi đến vị trí mới
- copy_backward: sao chép một phạm vi các phần tử theo thứ tự ngược lại
- move(C++11): di chuyển một phạm vi các phần tử đến vị trí mới
- move_backward(C++11): di chuyển một phạm vi các phần tử theo thứ tự ngược lại đến vị trí mới
- fill: gán một giá trị cho mỗi phần tử trong một phạm vi
- fill_n: gán một giá trị cho một số lượng phần tử trong một phạm vi
- transform: áp dụng một hàm cho một phạm vi các phần tử và lưu kết quả vào một phạm vi đích
- generate: gán kết quả của các lần gọi hàm liên tiếp cho mỗi phần tử trong một phạm vi
- generate_n: gán kết quả của các lần gọi hàm liên tiếp cho một số lượng phần tử trong một phạm vi
- remove, remove_if: xóa các phần tử thoả mãn một điều kiện cho trước
- remove_copy, remove_copy_if: sao chép một phạm vi các phần tử, loại bỏ các phần tử thoả mãn một điều kiện cho trước
- replace, replace_if: thay thế tất cả các giá trị thoả mãn một điều kiện cho trước bằng một giá trị khác
- replace_copy, replace_copy_if: sao chép một phạm vi các phần tử, thay thế các phần tử thoả mãn một điều kiện cho trước bằng một giá trị khác
- swap: hoán đổi giá trị của hai đối tượng
- swap_ranges: hoán đổi hai phạm vi các phần tử với nhau
- iter_swap: hoán đổi các phần tử được trỏ bởi hai vị trí trong chuỗi
- reverse: đảo ngược thứ tự các phần tử trong một phạm vi
- reverse_copy: tạo một bản sao của một phạm vi được đảo ngược
- rotate: xoay thứ tự các phần tử trong một phạm vi
- rotate_copy: sao chép và xoay một phạm vi các phần tử
- random_shuffle, shuffle(C++11): xáo trộn ngẫu nhiên các phần tử trong một phạm vi
- sample(C++17): lựa chọn n phần tử ngẫu nhiên từ một chuỗi
- unique: loại bỏ các phần tử trùng liên tiếp trong một phạm vi
- unique_copy: tạo một bản sao của một phạm vi các phần tử mà không có phần tử trùng liên tiếp

## Các phép tách phân đoạn
Được định nghĩa trong header `<algorithm>`.
- is_partitioned(C++11): kiểm tra xem một phạm vi đã được tách phân đoạn hay chưa
- partition: tách phân đoạn một phạm vi thành hai phần, với các phần tử thoả mãn một điều kiện cho trước được đặt phía trước
- partition_copy(C++11): sao chép các phần tử thoả mãn một điều kiện vào một phạm vi đích, các phần tử không thoả mãn được sao chép vào phạm vi khác
- stable_partition: tách phân đoạn một phạm vi thành hai phần, duy trì thứ tự tương đối của các phần tử
- partition_point(C++11): tìm điểm chia phân đoạn, nơi mà các phần tử thoả mãn điều kiện đầu tiên kết thúc và các phần tử không thoả mãn bắt đầu

## Các phép sắp xếp
Được định nghĩa trong header `<algorithm>`.
- is_sorted(C++11): kiểm tra xem một phạm vi đã được sắp xếp theo thứ tự tăng dần hay chưa
- is_sorted_until(C++11): tìm phần tử cuối cùng trong một phạm vi đã được sắp xếp theo thứ tự tăng dần
- sort: sắp xếp một phạm vi theo thứ tự tăng dần
- partial_sort: sắp xếp N phần tử đầu tiên trong một phạm vi
- partial_sort_copy: sao chép và sắp xếp một phạm vi các phần tử
- stable_sort: sắp xếp một phạm vi các phần tử trong khi duy trì thứ tự giữa các phần tử bằng nhau
- nth_element: sắp xếp một phạm vi sao cho phần tử đã cho được đặt ở vị trí đúng

## Các phép tìm kiếm nhị phân
Được định nghĩa trong header `<algorithm>`.
- lower_bound: trả về một iterator đến phần tử đầu tiên không nhỏ hơn giá trị đã cho trong một phạm vi đã được sắp xếp
- upper_bound: trả về một iterator đến phần tử đầu tiên lớn hơn giá trị đã cho trong một phạm vi đã được sắp xếp
- binary_search: xác định xem một phần tử có tồn tại trong một phạm vi đã được sắp xếp một cách bán thứ tự hay không
- equal_range: trả về phạm vi các phần tử khớp với một khóa cụ thể trong một phạm vi đã được sắp xếp

## Các phép toán khác trên phạm vi đã được sắp xếp
Được định nghĩa trong header `<algorithm>`.
- merge: trộn hai phạm vi đã được sắp xếp
- inplace_merge: trộn hai phạm vi đã được sắp xếp trực tiếp trên chúng
- includes: trả về true nếu một chuỗi là một chuỗi con của chuỗi khác
- set_difference: tính hiệu của hai tập hợp
- set_intersection: tính giao của hai tập hợp
- set_symmetric_difference: tính phần tử khác nhau đối xứng của hai tập hợp
- set_union: tính hợp của hai tập hợp

## Các phép toán trên heap
Được định nghĩa trong header `<algorithm>`.
- is_heap: kiểm tra xem một phạm vi đã cho có phải là heap tối đa hay không
- is_heap_until: tìm phạm vi con lớn nhất trong một phạm vi đã cho là heap tối đa
- make_heap: tạo một heap tối đa từ một phạm vi các phần tử
- push_heap: thêm một phần tử vào heap tối đa
- pop_heap: xóa phần tử lớn nhất từ heap tối đa
- sort_heap: chuyển một heap tối đa thành một phạm vi các phần tử được sắp xếp tăng dần

## Các phép toán tìm giá trị tối thiểu/tối đa
Được định nghĩa trong header `<algorithm>`.
- max: trả về giá trị lớn hơn trong hai giá trị đã cho
- max_element: trả về phần tử lớn nhất trong một phạm vi
- min: trả về giá trị nhỏ hơn trong hai giá trị đã cho
- min_element: trả về phần tử nhỏ nhất trong một phạm vi
- minmax: trả về giá trị nhỏ nhất và lớn nhất trong một cặp giá trị đã cho
- minmax_element: trả về phần tử nhỏ nhất và lớn nhất trong một phạm vi
- clamp: giới hạn một giá trị trong khoảng giới hạn đã cho

## Các phép so sánh
Được định nghĩa trong header `<algorithm>`.
- equal: xác định xem hai tập hợp các phần tử có giống nhau hay không
- lexicographical_compare: trả về true nếu một phạm vi được sắp xếp theo thứ tự từ điển nhỏ hơn một phạm vi khác
- lexicographical_compare_three_way: so sánh hai phạm vi sử dụng ba phép so sánh

## Các phép hoán vị
Được định nghĩa trong header `<algorithm>`.
- is_permutation: xác định xem một chuỗi có phải là một hoán vị của chuỗi khác hay không
- next_permutation: tạo ra hoán vị kế tiếp lớn hơn của một phạm vi các phần tử
- prev_permutation: tạo ra hoán vị trước đó nhỏ hơn của một phạm vi các phần tử

## Các phép toán số học
Được định nghĩa trong header `<numeric>`.
- iota(C++11): điền vào một phạm vi với các giá trị tăng dần
- accumulate: tính tổng hoặc gấp gọn một phạm vi các phần tử
- inner_product: tính tích vô hướng của hai phạm vi các phần tử
- adjacent_difference: tính các hiệu chênh lệch giữa các phần tử liền kề trong một phạm vi
- partial_sum: tính tổng phần tử của một phạm vi theo từng bước

## Các phép toán trên bộ nhớ chưa khởi tạo
Được định nghĩa trong header `<memory>`.
- uninitialized_copy: sao chép một phạm vi các đối tượng vào một vùng nhớ chưa được khởi tạo
- uninitialized_copy_n(C++11): sao chép một số lượng đối tượng vào một vùng nhớ chưa được khởi tạo
- uninitialized_fill: sao chép một đối tượng vào một vùng nhớ chưa được khởi tạo, được xác định bởi một phạm vi
- uninitialized_fill_n: sao chép một đối tượng vào một vùng nhớ chưa được khởi tạo, được xác định bởi một điểm bắt đầu và số lượng
- uninitialized_move (C++17): di chuyển một phạm vi các đối tượng vào một vùng nhớ chưa được khởi tạo
- uninitialized_move_n (C++17): di chuyển một số lượng đối tượng vào một vùng nhớ chưa được khởi tạo
- uninitialized_default_construct (C++17): khởi tạo các đối tượng bằng khởi tạo mặc định trong một vùng nhớ chưa được khởi tạo, được xác định bởi một phạm vi
- uninitialized_default_construct_n (C++17): khởi tạo các đối tượng bằng khởi tạo mặc định trong một vùng nhớ chưa được khởi tạo, được xác định bởi một điểm bắt đầu và một số lượng

## Thư viện C
Được định nghĩa trong header `<cstdlib>`.
- qsort: sắp xếp một dãy các phần tử với kiểu không xác định
- bsearch: tìm kiếm một phần tử trong một mảng với kiểu không xác định