#include <DHT.h>

#define DHTPIN 2    //رجل البيانات 
#define DHTTYPE DHT22 //نوع الحساس

DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600);  // الاتصال مع الحاسوب
  dht.begin();
}

void loop() {
  delay(2000);  //قراءة كل ثانيتين 

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // مئوي


  if(isnan(humidity) || isnan(temperature))
  {
    Serial.println("ERROR:Failed to read from DHT22");
    return;
  }

 
  Serial.print("TEMP:");
  Serial.print(temperature);
  Serial.print(" ,HUM:");
  Serial.print(humidity);

}