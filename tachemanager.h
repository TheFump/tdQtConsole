#ifndef TACHEMANAGER
#define TACHEMANAGER

class TacheManager {
private :
   static TacheManager m_instance;
    //~TacheManager(){}
    TacheManager& operator= (TacheManager& t);
    TacheManager(){}
public :
   static TacheManager& getInstance();
   QString bonjour();

};

#endif // TACHEMANAGER

