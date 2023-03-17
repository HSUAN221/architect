// Copyright (c)
#ifndef SRC_ARCHITECT_SORT_HPP_
#define SRC_ARCHITECT_SORT_HPP_
namespace architect {

class MergeSortTest;
class MergeSort {
 private:
    std::vector<int> merge(const std::vector<int>& arr1, const std::vector<int>& arr2) {
        std::vector<int> merged_arr;
        merged_arr.reserve(arr1.size() + arr2.size());
        auto iter1 = arr1.begin();
        auto iter2 = arr2.begin();

        while (iter1 != arr1.end() && iter2 != arr2.end()) {
            const auto& arr1_val = *iter1;
            const auto& arr2_val = *iter2;
            if (arr1_val <= arr2_val) {
                merged_arr.push_back(arr1_val);
                iter1++;
            } else {
                merged_arr.push_back(arr2_val);
                iter2++;
            }
        }

        if (iter1 == arr1.end()) {
            while (iter2 != arr2.end()) {
                const auto& arr2_val = *iter2;
                merged_arr.push_back(arr2_val);
                iter2++;
            }
        } else {
            while (iter1 != arr1.end()) {
                const auto& arr1_val = *iter1;
                merged_arr.push_back(arr1_val);
                iter1++;
            }
        }
        return merged_arr;
    }

 public:
    MergeSort() = default;

    std::vector<int> run(const std::vector<int>& arr) {
        if (arr.size() == 1) return arr;
        int mid = arr.size() / 2;
        std::vector<int> left(arr.begin(), arr.begin() + mid);
        std::vector<int> right(arr.begin() + mid, arr.end());
        auto left_is_sorted = run(left);
        auto right_is_sorted = run(right);
        return merge(left_is_sorted, right_is_sorted);
    }

    friend class MergeSortTest;
};

class MergeSortTest {
 private:
    MergeSort ms_;

 public:
    MergeSortTest() = default;

    bool runMergeTest() {
        std::vector<int> expected = {3, 4, 5, 12};
        std::vector<int> arr1 = {};
        std::vector<int> arr2 = {3, 4, 5, 12};
        auto result = ms_.merge(arr1, arr2);
        // for (const auto& i : result)
        //     std::cout << i << std::endl;
        return result == expected;
    }
};

//  in-place
class QuickSort {
 private:
    int randomizePivot(int left_idx, int right_idx) {
        std::random_device rd();
        std::default_random_engine generator(rd());
        std::uniform_int_distribution unii(left_idx, right_idx);
        return unii(generator);
    }

    int partition(std::vector<int>& arr, int left_idx, int right_idx) {
        auto pivot = randomizePivot();
        std::swap(arr[pivot], arr[right_idx);
        auto i = left_idx;
        for (size_t j = 0; j < right_idx - 1; ++j) {
            if (arr[j] < pivot) {
                // std::swap()
            }
        }
        return pivot;
    }

 public:

    friend class QuickSortTest;
};

class QuickSortTest {
 private:
    QuickSort qs_;

 public:
    QuickSortTest() = default;

    bool runPartitionTest() {
        std::vector<int> expected = {1, 2, 3, 4, 5};
        std::vector<int> arr = {4, 5, 3, 1, 2};
        auto pivot = qs_.partition(arr, 0, static_cast<int>(arr.size())-1);
        std::cout << "pivot= " << pivot << std::endl;
        // for (const auto& i : result)
        //     std::cout << i << std::endl;
        return arr == expected;
    }
};


}  // namespace architect
#endif  // SRC_ARCHITECT_SORT_HPP_
