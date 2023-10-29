#include <iostream>
#include <vector>

// Define the strategy interface
template <typename T>
class SortStrategy
{
public:
    virtual void sort(std::vector<T>& data) = 0;
};

// Define some concrete strategy implementations
template <typename T>
class BubbleSort : public SortStrategy<T>
{
public:
    void sort(std::vector<T>& data) override
    {
        // Perform bubble sort on the data
        std::cout << "Performing bubble sort" << std::endl;
    }
};

template <typename T>
class QuickSort : public SortStrategy<T>
{
public:
    void sort(std::vector<T>& data) override
    {
        // Perform quick sort on the data
        std::cout << "Performing quick sort" << std::endl;
    }
};

// Define the context class that uses the strategy
template <typename T>
class SortContext
{
public:
    SortContext(SortStrategy<T>* strategy) : m_strategy(strategy) {}

    void setStrategy(SortStrategy<T>* strategy)
    {
        m_strategy = strategy;
    }

    void sort(std::vector<T>& data)
    {
        m_strategy->sort(data);
    }

private:
    SortStrategy<T>* m_strategy;
};
