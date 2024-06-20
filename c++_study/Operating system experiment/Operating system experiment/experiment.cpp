#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <list>
#include <algorithm>
#include <ctime>

#define N 320
#define PAGE_SIZE 10
#define VIRTUAL_MEMORY_PAGES 32

// FIFO 页面置换算法
int FIFO(const std::vector<int>& pageAddresses, int memoryCapacity) {
    std::unordered_set<int> pages;//哈希索引
    std::queue<int> fifoQueue; //队列控制最长存在时间的数据
    int pageFaults = 0;

    for (auto page : pageAddresses) {
        if (pages.find(page) == pages.end()) {
            pageFaults++;
            if (pages.size() == memoryCapacity) {
                int pageToRemove = fifoQueue.front();
                fifoQueue.pop();
                pages.erase(pageToRemove);
            }
            pages.insert(page);
            fifoQueue.push(page);
        }
    }

    return pageFaults;
}

// LRU 页面置换算法
//  使用时间最短的被替代
int LRU(const std::vector<int>& pageAddresses, int memoryCapacity) {
    std::unordered_set<int> pages;
    std::unordered_map<int, std::list<int>::iterator> pageMap;
    std::list<int> lruList;
    int pageFaults = 0;

    for (int page : pageAddresses) {
        if (pages.find(page) == pages.end()) {
            pageFaults++;
            if (pages.size() == memoryCapacity) {
                int pageToRemove = lruList.back();
                lruList.pop_back();
                pages.erase(pageToRemove);
                pageMap.erase(pageToRemove);
            }
            pages.insert(page);
            lruList.push_front(page);
            pageMap[page] = lruList.begin();
        }
        else {
            lruList.erase(pageMap[page]);
            lruList.push_front(page);
            pageMap[page] = lruList.begin();
        }
    }

    return pageFaults;
}

// OPT 页面置换算法
int OPT(const std::vector<int>& pageAddresses, int memoryCapacity) {
    std::unordered_set<int> pages;
    int pageFaults = 0;

    for (int i = 0; i < pageAddresses.size(); ++i) {
        int page = pageAddresses[i];
        if (pages.find(page) == pages.end()) {
            pageFaults++;
            if (pages.size() == memoryCapacity) {
                int farthest = i;
                int pageToRemove = -1;
                for (int p : pages) {
                    auto it = std::find(pageAddresses.begin() + i + 1, pageAddresses.end(), p);
                    if (it == pageAddresses.end()) {
                        pageToRemove = p;
                        break;
                    }
                    else {
                        if (it - pageAddresses.begin() > farthest) {
                            farthest = it - pageAddresses.begin();
                            pageToRemove = p;
                        }
                    }
                }
                pages.erase(pageToRemove);
            }
            pages.insert(page);
        }
    }

    return pageFaults;
}

int main() {
    // 初始化随机数种子
    std::srand(std::time(0));

    // 定义指令序列
    std::vector<int> instructions;

    // 在 [0, 319] 区间内随机选择一个起始点 M
    int M = std::rand() % 320;
    instructions.push_back(M);

    // 生成指令序列
    for (int i = 1; i < N; ++i) {
        int lastInstruction = instructions.back();
        int choice = std::rand() % 4;

        if (choice == 0 || choice == 1) {
            // 50%的指令是顺序执行的
            instructions.push_back((lastInstruction + 1) % 320);
        }
        else if (choice == 2) {
            // 25%的指令是均匀分布在前地址部分
            instructions.push_back(std::rand() % (M + 2));
        }
        else {
            // 25%的指令是均匀分布在后地址部分
            instructions.push_back(M + 2 + std::rand() % (320 - M - 2));
        }
    }

    // 将指令序列转换成页地址流
    std::vector<int> pageAddresses;
    for (int i = 0; i < N; ++i) {
        int virtualAddress = instructions[i]; // 虚存地址即为指令地址
        int pageAddress = virtualAddress / PAGE_SIZE; // 计算页地址
        pageAddresses.push_back(pageAddress);
    }

    // 测试不同内存容量下的命中率
    for (int memoryCapacity = 4; memoryCapacity <= 32; ++memoryCapacity) {
        int fifoFaults = FIFO(pageAddresses, memoryCapacity);
        int lruFaults = LRU(pageAddresses, memoryCapacity);
        int optFaults = OPT(pageAddresses, memoryCapacity);

        double fifoHitRate = 1.0 - (double)fifoFaults / N;
        double lruHitRate = 1.0 - (double)lruFaults / N;
        double optHitRate = 1.0 - (double)optFaults / N;

        std::cout << "Memory Capacity: " << memoryCapacity << " pages" << std::endl;
        std::cout << "FIFO Hit Rate: " << fifoHitRate << std::endl;
        std::cout << "LRU Hit Rate: " << lruHitRate << std::endl;
        std::cout << "OPT Hit Rate: " << optHitRate << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
