# Backend for Controlling a WS2812B LED Strip

### Setup

Make sure to download the `onoff.go` and the `arduino.ino` files onto your computer. Open the `arduino.ino` file and upload its contents onto an arduino chip of your choice. However, it is important to note that the `arduino.ino` file uses the [FastLED library](https://github.com/FastLED/FastLED/wiki/Overview), and that in order to upload the file onto an arduino, you must first install the library.

Open the `onoff.go` file. Replace the `"COM4"` in `var ser, err = serial.OpenPort(&serial.Config{Name: "COM4", Baud: 115200})` (line 21) with the serial port your arduino chip is connected to.

In terminal, navigate to the directory containing your `onoff.go` file. Type `go run onoff.go` into your terminal and hit enter.

Your LED Strip backend is now being hosted on `http://localhost:8080`.


### Requests
#### getcolor

`http://localhost:8080/getcolor` is a GET request which returns a json in this format:
```
{
 "colors": [a, b, c, d, e...]
}
```
where a, b, c, d, e... are strings that consist of one hex color in form "#ABCDEF". Each element represents the color of the led at the index position of that element.

#### setcolor
`http://localhost:8080/setcolor` is a POST request, which requires you to send a json in the same format as the getcolor request.
```
{
 "colors": [a, b, c, d, e...]
}
```
This request updates the led to display the colors stored in the json. A response is also sent back in return. The response is a copy of the json sent in the request.
