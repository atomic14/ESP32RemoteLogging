#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "wifi_credentials.h"
#include "papertrail_credentials.h"
#include "PapertrailLogger.h"

PapertrailLogger *errorLog;
PapertrailLogger *warningLog;
PapertrailLogger *noticeLog;
PapertrailLogger *debugLog;
PapertrailLogger *infoLog;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  if (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println("WiFiConnection Failed");
    delay(5000);
    ESP.restart();
  }
  errorLog = new PapertrailLogger(PAPERTRAIL_HOST, PAPERTRAIL_PORT, LogLevel::Error, "\033[0;31m", "papertrail-test", "testing");
  warningLog = new PapertrailLogger(PAPERTRAIL_HOST, PAPERTRAIL_PORT, LogLevel::Warning, "\033[0;33m", "papertrail-test", "testing");
  noticeLog = new PapertrailLogger(PAPERTRAIL_HOST, PAPERTRAIL_PORT, LogLevel::Notice, "\033[0;36m", "papertrail-test", "testing");
  debugLog= new PapertrailLogger(PAPERTRAIL_HOST, PAPERTRAIL_PORT, LogLevel::Debug, "\033[0;32m","papertrail-test", "testing");
  infoLog = new PapertrailLogger(PAPERTRAIL_HOST, PAPERTRAIL_PORT, LogLevel::Info, "\033[0;34m", "papertrail-test", "testing");
  Serial.println("Up and running");
}


int count = 0;
void loop() {
  infoLog->println("Looping");
  infoLog->printf("In the loop %d\n", count);

  errorLog->printf("In the loop error %d\n", count);
  warningLog->printf("In the loop warning %d\n", count);
  noticeLog->printf("In the loop notice %d\n", count);
  debugLog->printf("In the loop debug %d\n", count);
  infoLog->printf("In the loop info %d\n", count);

  count++;
  delay(3000);
}
