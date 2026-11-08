#include "project/heap.h"

#include <algorithm>
#include <stdexcept>

MaxHeap::MaxHeap() = default;

MaxHeap::MaxHeap(const std::vector<int> &values)
{
    buildHeap(values);
}

bool MaxHeap::empty() const noexcept
{
    return data_.empty();
}

std::size_t MaxHeap::size() const noexcept
{
    return data_.size();
}

int MaxHeap::top() const
{
    if (empty())
    {
        throw std::logic_error("Heap is empty");
    }
    return data_.front();
}

bool MaxHeap::contains(int value) const
{
    for (int item : data_)
    {
        if (item == value)
        {
            return true;
        }
    }
    return false;
}

// insert value and restore the max heap property.
void MaxHeap::push(int value)
{
    data_.push_back(value);
    heapifyUp(data_.size() - 1);
}

// remove the maximum value and restore the max heap property.
int MaxHeap::pop()
{
    if (empty())
    {
        throw std::logic_error("Heap is empty");
    }
    int maximum = data_.front();

    if (data_.size() == 1)
    {
        data_.pop_back();
        return maximum;
    }
    data_.front() = data_.back();
    data_.pop_back();
    heapifyDown(0);
    return maximum;
}

// build a max heap from the given values.
void MaxHeap::buildHeap(const std::vector<int> &values)
{
    data_ = values;
    if (data_.empty())
    {
        return;
    }
    for (std::size_t i = data_.size() / 2; i > 0; --i)
    {
        heapifyDown(i - 1);
    }
}

// sort the heap values in ascending order.
// the original heap is unchanged.
std::vector<int> MaxHeap::heapSort()
{
    MaxHeap copy = *this;
    std::vector<int> sorted;
    sorted.reserve(copy.size());
    while (!copy.empty())
    {
        sorted.push_back(copy.pop());
    }
    std::reverse(sorted.begin(), sorted.end());
    return sorted;
}

std::vector<int> MaxHeap::toVector() const
{
    return data_;
}

std::size_t MaxHeap::parentIndex(std::size_t index)
{
    if (index == 0)
    {
        return 0;
    }
    return (index - 1) / 2;
}

std::size_t MaxHeap::leftChildIndex(std::size_t index)
{
    return (2 * index) + 1;
}

std::size_t MaxHeap::rightChildIndex(std::size_t index)
{
    return (2 * index) + 2;
}

// move the value at the given index up until the max heap property is restored.
void MaxHeap::heapifyUp(std::size_t index)
{
    while (index > 0)
    {
        std::size_t parent = parentIndex(index);
        if (data_[parent] >= data_[index])
        {
            break;
        }
        swap(data_[parent], data_[index]);
        index = parent;
    }
}

// move the value at the given index down until the max heap property is restored.
void MaxHeap::heapifyDown(std::size_t index)
{
    while (index < data_.size())
    {
        std::size_t largest = index;
        std::size_t left = leftChildIndex(index);
        std::size_t right = rightChildIndex(index);

        if (left < data_.size() && data_[left] > data_[largest])
        {
            largest = left;
        }
        if (right < data_.size() && data_[right] > data_[largest])
        {
            largest = right;
        }
        if (largest == index)
        {
            break;
        }
        swap(data_[index], data_[largest]);
        index = largest;
    }
}

void MaxHeap::swap(int &a, int &b)
{
    std::swap(a, b);
}

bool MaxHeap::isValidHeap() const
{
    for (std::size_t i = 1; i < data_.size(); ++i)
    {
        if (data_[parentIndex(i)] < data_[i])
        {
            return false;
        }
    }
    return true;
}
