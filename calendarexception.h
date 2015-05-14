#ifndef CALENDAREXCEPTION
#define CALENDAREXCEPTION

class CalendarException{
public:
    CalendarException(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
};


#endif // CALENDAREXCEPTION

