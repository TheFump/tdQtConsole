#include "tachemanager.h"
TacheManager TacheManager::m_instance = TacheManager();

TacheManager &TacheManager::getInstance()
{
    return m_instance;
}

QString TacheManager::bonjour(){QString b = "bonjour"; return b;}

