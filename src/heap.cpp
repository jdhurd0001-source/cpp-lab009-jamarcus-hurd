
#include "project/heap.h"

#include <algorithm>
#include <stdexcept>

// Default constructor
MaxHeap::MaxHeap() = default;

// Construct a heap from a vector
MaxHeap::MaxHeap(const std::vector<int>& values) {
    buildHeap(values);
}

// Check whether the heap is empty
bool MaxHeap::empty() const noexcept {
    return data_.empty();
}

// Return the number of elements
std::size_t MaxHeap::size() const noexcept {
    return data_.size();
}

// Retrieve the maximum element
int MaxHeap::top() const {
    if (empty()) {
        throw std::logic_error("Heap is empty");
    }

    return data_.front();
}

// Search for a value in the heap
bool MaxHeap::contains(int value) const {
    for (int item : data_) {
        if (item == value) {
            return true;
        }
    }

    return false;
}

// Insert a value and restore the heap property
void MaxHeap::push(int value) {
    data_.push_back(value);

    heapifyUp(data_.size() - 1);
}

// Remove and return the maximum element
int MaxHeap::pop() {
    if (empty()) {
        throw std::logic_error("Heap is empty");
    }

    int maximum = data_.front();

    // Move the last element to the root
    data_.front() = data_.back();
    data_.pop_back();

    // Restore the heap property
    if (!empty()) {
        heapifyDown(0);
    }

    return maximum;
}

// Build a max-heap using bottom-up construction
void MaxHeap::buildHeap(
    const std::vector<int>& values) {

    data_ = values;

    // Start with the last internal node
    for (std::size_t i = data_.size() / 2;
         i > 0; --i) {

        heapifyDown(i - 1);
    }
}

// Return elements in ascending sorted order
std::vector<int> MaxHeap::heapSort() {
    // Copy the heap to preserve the original
    MaxHeap temporary = *this;

    std::vector<int> sorted;
    sorted.reserve(data_.size());

    // Extract maximum elements
    while (!temporary.empty()) {
        sorted.push_back(temporary.pop());
    }

    // Convert descending order to ascending order
    std::reverse(sorted.begin(), sorted.end());

    return sorted;
}

// Return the heap's vector representation
std::vector<int> MaxHeap::toVector() const {
    return data_;
}

// Calculate the parent index
std::size_t MaxHeap::parentIndex(
    std::size_t index) {

    if (index == 0) {
        return 0;
    }

    return (index - 1) / 2;
}

// Calculate the left child index
std::size_t MaxHeap::leftChildIndex(
    std::size_t index) {

    return (2 * index) + 1;
}

// Calculate the right child index
std::size_t MaxHeap::rightChildIndex(
    std::size_t index) {

    return (2 * index) + 2;
}

// Restore the heap property after insertion
void MaxHeap::heapifyUp(std::size_t index) {
    while (index > 0) {
        std::size_t parent = parentIndex(index);

        // Stop when the heap property is satisfied
        if (data_[parent] >= data_[index]) {
            break;
        }

        // Move the larger element upward
        swap(data_[parent], data_[index]);

        index = parent;
    }
}

// Restore the heap property after removal
void MaxHeap::heapifyDown(std::size_t index) {
    while (index < data_.size()) {
        std::size_t largest = index;

        std::size_t left = leftChildIndex(index);
        std::size_t right = rightChildIndex(index);

        // Compare with the left child
        if (left < data_.size() &&
            data_[left] > data_[largest]) {

            largest = left;
        }

        // Compare with the right child
        if (right < data_.size() &&
            data_[right] > data_[largest]) {

            largest = right;
        }

        // Stop when the heap property is satisfied
        if (largest == index) {
            break;
        }

        // Move the larger child upward
        swap(data_[index], data_[largest]);

        index = largest;
    }
}

// Swap two elements
void MaxHeap::swap(int& a, int& b) {
    std::swap(a, b);
}

// Verify that the max-heap property is maintained
bool MaxHeap::isValidHeap() const {
    for (std::size_t i = 1;
         i < data_.size(); ++i) {

        if (data_[parentIndex(i)] < data_[i]) {
            return false;
        }
    }

    return true;
}
