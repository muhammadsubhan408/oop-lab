#include<iostream>
#include<string>
using namespace std;

const int MAX_LOGS = 1000;

class Logger {
private:
    string logs[MAX_LOGS];
    int logCount;

    string getSeverityTag(const string& severity) const {
        return "[" + severity + "]";
    }

    string formatLog(const string& severity, const string& module, const string& message) const {
        return getSeverityTag(severity) + " [" + module + "] " + message;
    }

    void storeLog(const string& formattedLog) {
        if (logCount < MAX_LOGS) {
            logs[logCount++] = formattedLog;
        } else {
            for (int i = 1; i < MAX_LOGS; ++i) {
                logs[i - 1] = logs[i];
            }
            logs[MAX_LOGS - 1] = formattedLog;
        }
    }

public:
    Logger() : logCount(0) {}

    void logInfo(const string& module, const string& message) {
        storeLog(formatLog("INFO", module, message));
    }

    void logWarning(const string& module, const string& message) {
        storeLog(formatLog("WARN", module, message));
    }

    void logError(const string& module, const string& message) {
        storeLog(formatLog("ERROR", module, message));
    }

    friend class Auditor;
};

class Auditor {
    string authToken;

    bool isAuthenticated() const {
        return authToken == "admin123";
    }

public:
    Auditor(const string& token) : authToken(token) {}

    void viewLogs(const Logger& logge) const{
        if (!isAuthenticated()) {
            cout << "Access denied. Invalid credentials.\n";
            return;
        }

        cout << "\n=== LOG ENTRIES ===\n";
        for(int i = 0; i < logger.logCount; ++i){
            cout << logger.logs[i] << "\n";
        }
    }
};

int main(){
    Logger logger;

    logger.logInfo("Network", "Connected to server.");
    logger.logWarning("Database", "Slow query detected.");
    logger.logError("Security", "Unauthorized access attempt.");
    logger.logInfo("UI", "User clicked submit.");
    logger.logWarning("Network", "Unstable connection.");
    logger.logError("Storage", "Out of disk space.");

    Auditor guest("guest");
    guest.viewLogs(logger);

    cout<<"\n";

    Auditor admin("admin123");
    admin.viewLogs(logger);

    return 0;
}

