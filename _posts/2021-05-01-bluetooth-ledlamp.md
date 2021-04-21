---
layout: post
title:  "Bluetooth Neopixel lamp"
featured: false
published: true
authors: [stefaan]
lowtech: false
midtech: true
hightech: false
DIT: true
DIY: true
CHALLENGE: false
moeilijkheidsgraad_1_3: 2
prijs_1_3: 2
pijler_tinkering : false
pijler_design_thinking : false
pijler_digitale_fabricatie : true
pijler_physical_computing : true
licence: CCBY-NC-SA 
categories: [arduino, physical computing, software]
image: assets/images/2021-05-01-bluetooth_ledlamp/lampen.png
tijd: 2 uur tot 3 uur
print: false
downloads: 
  - name: 'android app'
    file: assets/images/2021-05-01-bluetooth_ledlamp/INGEGNO_Bluetooth_controller.apk
  - name: 'arduino bluetooth initialisatie ino'
    file: assets/images/2021-05-01-bluetooth_ledlamp/HC-06_setup.ino
  - name: 'arduino led besturing ino'
    file: assets/images/2021-05-01-bluetooth_ledlamp/MIT_Bluetooth.ino
  - name: 'android app sourcecode'
    file: assets/images/2021-05-01-bluetooth_ledlamp/INGEGNO_Bluetooth_controller.aia
  - name: 'arduino led besturing blokkencode'
    file: assets/images/2021-05-01-bluetooth_ledlamp/MIT_Bluetooth.xml
materialen: [
    1 arduino microcontroller en bijhorende USB kabel,
    1 Neopixel ledstrip,
    1 HC06 bluetooth ontvanger,
    7 jumper kabels
      ]
tools: [
      Android smartphone,
      PC met internetverbinding,
      ]
      
---

Stuur een ledstrip aan met jouw smartphone.

*Deze handleiding werd ontwikkeld door **Stefaan Vandeputte** voor Maakbib*

## Benodigdheden

<p style="margin: 0 0 0 0;"><strong>Materialen:</strong></p>
<div class="benodigdheden">
  <ul>
    <li>HC06 bluetooth receiver</li>
    <li>Arduino Nano en usb kabel</li>
    <li>Neopixel ledstrip</li>
    <li>7 jumper kabels</li>
 </ul>
</div>

{% include benodigdheden.html %}
<img src="{{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/nodig.jpg" alt="nodig" style="zoom: 67%;" />

## Stappen
+ verbind de arduino met de HC06 bluetooth ontvanger
+ verbind je smartphone met de HC06 bluetooth ontvanger
+ kies de juiste instellingen in arduino
+ initialiseer de HC06 bluetooth ontvanger (optioneel)
+ verbind de arduino met de ledstrip
+ laad het ino-bestand op via de Arduino editor
+ installeer de app


### verbind de arduino met de bluetooth receiver

Je kan om het even welk arduinobordje gebruiken , hier gebruiken we een Arduino Nano.

<img src="{{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/schema1.png" alt="Materialen" style="zoom:100%;" />

| **Nano** |      | HC06 |
| :------: | ---- | :--: |
|   3.3V   |      | Vcc  |
|   Gnd    |      | Gnd  |
|    D5    |      | RXD  |
|    D4    |      | TXD  |

<img src="{{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/CONN_HC06.png" alt="Materialen" style="zoom:50%;" />d

Verbind nu de Arduino Nano via de USB kabel met jouw computer.
Op de Bluetooth module begint een rood led lichtje snel te pinken, de bluetooth module is nu actief.

### verbind je smartphone met de HC06 bluetooth ontvanger

Activeer nu Bluetooth op jouw smartphone :   <img src="{{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/BT_AAN.png" alt="Materialen" style="zoom:50%;" />
daarna zie je bij `beschikbare apparaten` `HC06 `verschijnen: 

<img src="{{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/BT_LIJST_NOK.png" alt="Materialen" style="zoom:50%;" />

Klik nu op `HC06` , je krijgt nu eenmalig een scherm om te koppelen , vul hier de pincode in.

<img src="{{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/BT_KOPPEL.jpg" style="zoom:50%;" />

### Kies de juiste instellingen in Arduino
Open de Arduino editor.
In het menu `Hulpmiddelen`

![Materialen]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/hulpmiddelen.png) 

 kies je `Board` en daarna `Arduino AVR Boards`

![Materialen]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/AVR-boards.png)

en in de lijst kies je dan 

![Materialen]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/nano.png)

Daarna kies je in het menu `Hulpmiddelen` het item `Processor`

![Materialen]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/processor.png)

Hier kies je voor `ATmega328P`, of als je een ouder Nano bordje hebt dan kies je `ATmega328P (old bootloader)`.
Weet je niet wat kiezen , probeer er dan een.  Als het straks niet werkt neem dan de andere.

### Initialiseer de HC06 bluetooth ontvanger (optioneel )

Als je wil kan je de naam en het pincode van de HC06 bluetooth ontvanger wijzigen.
Hiervoor moeten we een Arduino script ( ino bestand) opladen op de Arduino Nano.
Open de Arduino IDE,  als je een eerder script te zien krijgt kies dan `Bestand` > `nieuw ` om een nieuw script te maken. 
Download het Arduino script  [hier is het script]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth_ledlamp/HC-06_setup.ino) voor de initialisatie , open het en kopieer het script in de Arduino editor.

Klik op het pijtje naar rechts om de code te laden op je Nano bordje.

![Materialen]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/upload.png)

Als de code opgeladen is , open dan de seriële monitor van de Arduino IDE: klik op het vergrootglas rechts op de knoppenbalk

![Materialen]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/monitor.png)

De seriële monitor opent:

<img src="{{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/serieel.png" alt="Materialen" style="zoom: 67%;" />

Hierin moet je enkele zaken juist zetten:
* kies voor `Geen regeleinde`  en voor `9600 baud`
Als alles goed is kan je nu communiceren met je Bluetooth bordje.
Tik in het invoerveld bovenaan ```AT``` in, druk op enter of klik op `Verzenden `en je krijgt `OK` als antwoord terug.

![Materialen]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/AT_OK.png)

Tik in het invoerveld bovenaan ```AT+VERSION``` in, je krijgt `OK` en de versie van de Bluetooth controller als antwoord terug.

![Materialen]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/AT_VERSIE.png)

In dit geval is de versie dus `linvorV1.8` .
Je kan echter ook een andere versie hebben  `3.0-20170609`.
Volgende stappen hoef je dus niet te doen.

Je kan de naam van de HC06 Bluetooth ontvanger aanpassen: b.v. naar `HC06_LED`
Voor `linvorV1.8` : tik in het invoerveld bovenaan ```AT+NAMEHC06_LED``` in, je krijgt `OKsetname` als antwoord terug.
Voor `3.0-20170609`: tik in het invoerveld bovenaan ```AT+NAME:HC06_LED``` in, je krijgt `OK` als antwoord terug.

Je kan nu ook de pincode veranderen naar b.v. `9876` ( standaard staat die ingesteld op `0000` of op `1234` ).
Voor `linvorV1.8` : tik in het invoerveld bovenaan ```AT+PIN9876``` in, je krijgt `OKsetpin` als antwoord terug.
Voor `3.0-20170609`: tik in het invoerveld bovenaan ```AT+PSWD:"9876"``` in, je krijgt `OK` als antwoord terug.

### verbind de arduino met de ledstrip

![Materialen]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/schema.png)

| **Nano** |      |    LEDSTRIP    |
| :------: | ---- | :------------: |
|    5V    |      | Vcc / DC power |
|   Gnd    |      |      Gnd       |
|    D6    |      |   Data input   |

### laad het ino-bestand op via de Arduino editor

Controleer eerst of je de Arduino bibliotheek voor het werken met Neopixel leds hebt:
Ga naar het menu `Hulpmiddelen` > `Bibliotheken beheren`

![Materialen]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/hulpmiddelen_bib.png)

Tik in het zoekvak bovenaan `Neopixel` in:

<img src="{{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/bibliotheek.png" alt="Materialen" style="zoom: 67%;" />

Selecteer `Adafruit Neopixel` in de lijst.
Als dit reeds geïnstalleerd is zoals hierboven, dan kan je eventueel updaten, anders kies je voor `installeren`
Download het Arduino-script  [hier is het script]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth_ledlamp/MIT_Bluetooth.ino) voor de besturing, open het en kopieer het script in de Arduino editor.
Klik op het pijtje naar rechts om de code te laden op je Nano bordje. 

![Materialen]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/upload2.png)

### installeer de app

Om de app op je smartphone te installeren moet je die eerst downloaden.
Surf op je smartphone naar dezelfde plaats als waar je nu leest. Je kan nu de app  [hier is de app]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth_ledlamp/INGEGNO_Bluetooth_controller.apk) downloaden. 
Ga naar je map met downloads en klik op het .apk bestand om te installeren. Je kan een melding krijgen in verband met onbekende apps maar die mag je wegklikken. 
Het kan ook nodig zijn om in de instellingen toestemming te geven om apps van een onbekende oorsprong te installeren. Geef dan tijdelijk die toestemming en verwijder ze weer na de installatie.

Zorg dat je Bluetooth aanstaat op je smartphone.
Open de app en `Selecteer Bluetooth apparaat`. 

<img src="{{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/APP_BT.jpg" alt="Materialen" style="zoom: 33%;" />

Als alles goed is krijg je een lijst met de Bluetooth apparaten waarmee je al eens verbonden bent geweest.

<img src="{{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/APP_LIST.jpg" alt="Materialen" style="zoom: 33%;" />

Selecteer daarin `HC06` ( als je de naam niet veranderd hebt ) of de nieuwe naam ( in dit geval`HC06_LED`) en na enkele seconden is jouw smartphone verbonden met de leds.

<img src="{{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/APP_UITLEG.jpg" alt="Materialen" style="zoom: 50%;" />

Het rode ledje op de HC06 bluetooth ontvanger brandt nu continue om aan te geven dat er een verbinding is.
En nu kan je de leds iedere kleur geven die je maar wil of de effectjes afspelen.

<div class="border_boxmaakbib01_img" markdown="1">
## extra's

    ### bluetooth codes zien
    
    Als je de Arduino IDE open staan hebt, open dan de seriële monitor.
    Je zal zien welke codes de app doorstuurt naar de HC06 bluetooth ontvanger.
    
    ![Materialen]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/ARD_LOG.png)
    De arduino moet de codes kennen die de app via bluetooth uitstuurt.
    Hieronder vind je deze codes:
|    **code**  | voorbeeld  | omschrijving                      |
| :----------: | ---------- | :-------------------------------: |
| `C`xxx.xxx.xxx | C200.0.150 | een RGB kleurcode                 |
|     `H`xxx     | H89        | de helderheid ( 0 --> 100 )       |
|     `EFF`x     | EFF6       | het gekozen effect ( 1 --> 8)     |


    ### code van arduino aanpassen met blokkencode
    
    Je kan zelf de arduino code aanpassen, als je dat heel eenvoudig wilt doen kan dat via Ingegno blokkencode
    
    Om te beginnen ga je naar <a href="http://blokkencode.ingegno.be" target="_blanc">blokkencode.ingegno.be</a>. Dit is een website waar we met blokken code kunnen schrijven voor de arduino.
    De blokkencode van het programma kan je  [hier is de code]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth_ledlamp/MIT_Bluetooth.xml) downloaden.
    Als je blokkencode af is kan je de code bij ``Arduino Source Code`` kopiëren en in je Arduino IDE zetten.
    
    ### code van de app aanpassen met blokkencode
    
    je kan zelfs de code van de app aanpassen met blokkencode.
    Daarvoor ga je <a href="https://appinventor.mit.edu/" target="_blanc">MIT App inventor</a>
    Maak een account aan en log in. Je kan vanaf dan in het Nederlands verder.
    Ga naar het menu `Projecten` en kies volgende optie:
    ![Materialen]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth-ledlamp/MIT_OPEN.png)
    Het `.aia` bestand van de app kan je [hier is de app]({{ site.baseurl }}/assets/images/2021-05-01-bluetooth_ledlamp/INGEGNO_Bluetooth_controller.aia) downloaden.


</div>