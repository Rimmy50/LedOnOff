# Backend for Controlling an LED Strip

### Setup

Make sure to download the `onoff.go` and the `arduino.ino` files onto your computer. Open the `arduino.ino` file and upload its contents onto an arduino chip of your choice. However, it is important to note that the `arduino.ino` file uses the FastLED library, and that in order to upload the file onto an arduino, you must first install the library.

Open the `onoff.go` file. Replace the `"COM4"` in `var ser, err = serial.OpenPort(&serial.Config{Name: "COM4", Baud: 115200})` (line 21) with the serial port of the arduino chip you are using.

In terminal, navigate to the directory containing your `onoff.go` file. Type `go run onoff.go` into your terminal and hit enter.

Your LED Strip backend is now being hosted on `http://localhost:8080`.


### Requests

The go server accepts two requests. One is `http://localhost:8080/getstate`, a GET request which returns a json in this format:
```
{
 "colors": [a, b, c, d, e...]
}
```
where a, b, c, d, e... are 
 
