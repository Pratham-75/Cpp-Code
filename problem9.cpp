// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <condition_variable>

// int g_sharedData = 0;
// int g_readersWaiting = 0;
// std::mutex mu;
// bool g_writerWaiting = false;
// std::condition_variable cond;

// void reader(int i)
// {
//     std::unique_lock<std::mutex> lg{mu};
//     while(g_writerWaiting)
//         cond.wait(lg);
//     ++g_readersWaiting;
//     // reading
//     std::cout << "\n reader #" << i << " is reading data = " << g_sharedData << '\n';
//     // end reading
//     --g_readersWaiting;
//     while(g_readersWaiting > 0)
//         cond.wait(lg);
//     cond.notify_one();
// }

// void writer(int i)
// {
//     std::unique_lock<std::mutex> lg{mu};
//     while(g_writerWaiting)
//         cond.wait(lg);
//     // writing
//     std::cout << "\n writer #" << i << " is writing\n";
//     g_sharedData += i * 10;
//     // end writing
//     g_writerWaiting = true;
//     while(g_readersWaiting > 0)
//         cond.wait(lg);
//     g_writerWaiting = false;
//     cond.notify_all();
// }//lg.unlock()


// int main()
// {
//     std::thread reader1{reader, 1};
//     std::thread reader2{reader, 2};
//     std::thread reader3{reader, 3};
//     std::thread reader4{reader, 4};
//     std::thread writer1{writer, 1};
//     std::thread writer2{writer, 2};
//     std::thread writer3{writer, 3};
//     std::thread writer4{reader, 4};

//     reader1.join();
//     reader2.join(); 
//     reader3.join();
//     reader4.join();
//     writer1.join();
//     writer2.join();
//     writer3.join();
//     writer4.join();

//     return(0);
// }