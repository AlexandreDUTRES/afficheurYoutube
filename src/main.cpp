#include <YoutubeApi.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <leds.h>

#define LED_PIN 12

#define YOUTUBE_API_KEY "" // your google apps API Token
#define YOUTUBE_CHANNEL_ID ""             // makes up the url of channel

//------- Replace the following! ------
char ssid[] = "";    // your network SSID (name)
char password[] = ""; // your network key

WiFiClientSecure client;
YoutubeApi apiYoutube(YOUTUBE_API_KEY, client);

unsigned long api_mtbs = 60000;     //mean time between api requests
unsigned long api_lasttime = 59000; //last time api request has been done

long youtube_subscribers = 0;

long getYoutubeSubscribers()
{
  if (apiYoutube.getChannelStatistics(YOUTUBE_CHANNEL_ID))
    return apiYoutube.channelStats.subscriberCount;
  else
    return youtube_subscribers;
}

void setup()
{

  Serial.begin(9600);

  sortCoordonates();

  FastLED.addLeds<WS2812, LED_PIN, GRB>(getLEDs(), MATRIX_WIDTH * MATRIX_HEIGHT);
  FastLED.clear();

  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");

  showBrandNumber("youtube", 0);
  delay(1000);
}

void loop()
{
  if (millis() - api_lasttime > api_mtbs)
  {
    long tmp = getYoutubeSubscribers();
    if (youtube_subscribers != tmp)
    {
      youtube_subscribers = tmp;
      showBrandNumber("youtube", youtube_subscribers);
    }

    api_lasttime = millis();
  }
}