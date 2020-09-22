#include "cereal/archives/binary.hpp"
#include "cereal/types/memory.hpp"

using namespace std;
 
struct MediaMsg
{
    MediaMsg()
    {
        userId = "11112222222";
        timeP = 2342342;
    }
 
    std::string userId;
    long long timeP;

    template<class Archive>
    void save(Archive & archive) const
    {
        cout << "save" << endl;
        archive(userId);
        archive(timeP);
    }
 
    template<class Archive>
    void load(Archive & archive)
    {
        cout << "load" << endl;
        archive(userId);
        archive(timeP);
    }
};
 
ostream& operator<<(ostream& o, MediaMsg& obj)
{
    o << "userId : " << obj.userId << endl;
    o << "timeP : " << obj.timeP << endl;
    return o;
}
 
void test_cereal()
{
 
    MediaMsg stData;
    cout << stData << endl;
    // output to memory.
    string strbuf0;
    ostringstream outs0;
    {
        cereal::BinaryOutputArchive archive(outs0);
        archive(stData);
    }
    cout << "outs0.str()=" << endl << outs0.str() << endl;
    cout << "strbuf0=" <<strbuf0.c_str()<< endl << strbuf0 << endl;
    strbuf0 = outs0.str();
    outs0.clear();
    cout << "strbuf0.size() : " << endl << strbuf0.size()<< endl;
 
    MediaMsg ttts0;
    string strbuff00;
    try {
         istringstream ins0(strbuf0);
         {
            cereal::BinaryInputArchive archive(ins0);
            archive(ttts0);
         }
    } catch (cereal::Exception & e) {
        cout << "error =" << endl << e.what() << endl;
    } catch (...) {
        cout << "error =" << endl << "2222" << endl;
    }
   
    cout << "ttts0=" << endl << ttts0 << endl;
 
    cout << "running cereal finished!" << endl;
}

int main(){
    test_cereal();
    return 0;
}
