#include <iostream>
#include <future>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;
using std::endl;

auto& out = std::cout;
auto& in = std::cin;

const path getAsuncName(const path _path) {
    return _path.filename();
}
double getAsuncSize(const path _path) {
    return file_size(_path);
}
void getAsuncTime(const path _path) {
    std::time_t _time = last_write_time(_path);
    out << std::asctime( std::localtime( &_time ) );
}

int main(int argc, char const *argv[]) {
    try {
        std::string address;
        out << endl
            << "Enter the path of file:" << endl
            << "example: 'explorer/file.dat' " << endl << endl;
        out << "input:\t";
        in  >> address;

        //  Проверка существования файла по введенному адресу
        if(!exists(address))
            throw std::runtime_error("ERROR: Wrong address! File does not exist!");

        //  Указываем путь к файлу file.dat.
        const path filePath = address;

        // РАЗДЕЛЯЕМ НА ПОТОКИ //

        //  ПОТОК #1 >> Получаем имя файла file.dat.
        std::future<const path> f1 ( std::async(getAsuncName, filePath) );

        //  ПОТОК #2 >> Получаем размер файла file.dat в байтах.
        std::future<double> f2 ( std::async(getAsuncSize, filePath) );

        //  ПОТОК #3 >> Получаем время последннего изменения файла file.dat.
        std::future<void> f3 ( std::async(std::launch::async, getAsuncTime, filePath) );

        //  Ожидаем выполнения ПОТОКОВ 1 и 2.
        out << endl << "Process..." << endl;
        f1.wait();
        f2.wait();

        out << endl
            << "name:\t\t" << f1.get() << endl
            << "size:\t\t" << (f2.get() / 1000) << " Kb" << endl;

        out << "date_mod:\t";

        //  Ожидаем выполнения ПОТОКА 3.
        f3.wait();
        f3.get();

        out << endl;

    } catch(const std::exception& e) {
        out << e.what() << endl;
    }

    return 0;
}
