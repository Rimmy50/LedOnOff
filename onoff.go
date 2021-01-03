package main

import (
	"encoding/json"
	"log"
	"net/http"
	"strconv"

	"github.com/gorilla/mux"
	"github.com/tarm/serial"
)

type ledState struct {
	COLORS []string `json:"colors,omitempty"`
}

// Stores the state of the LED at all times
var led ledState

// Defines new serial port
var ser, err = serial.OpenPort(&serial.Config{Name: "COM4", Baud: 115200})

// Returns the state of the LED
func getState(w http.ResponseWriter, req *http.Request) {
	json.NewEncoder(w).Encode(led)
}

func setColor(w http.ResponseWriter, req *http.Request) {
	_ = json.NewDecoder(req.Body).Decode(&led)

	data := []byte{}

	for i := 0; i < len(led.COLORS); i++ {

		val := led.COLORS[i][1:]

		a, err := strconv.ParseInt(val[0:2], 16, 64)
		if err != nil {
			log.Fatal(err)
		}
		x := byte(a)

		b, err := strconv.ParseInt(val[2:4], 16, 64)
		if err != nil {
			log.Fatal(err)
		}
		y := byte(b)

		c, err := strconv.ParseInt(val[4:6], 16, 64)
		if err != nil {
			log.Fatal(err)
		}
		z := byte(c)

		data = append(data, x, y, z)
	}

	_, err = ser.Write(data)
	if err != nil {
		log.Fatal(err)
	}

	json.NewEncoder(w).Encode(led)
}

func main() {
	if err != nil {
		log.Fatal(err)
	}

	r := mux.NewRouter()

	led = ledState{COLORS: nil}

	r.HandleFunc("/getcolor", getState).Methods("GET")
	r.HandleFunc("/setcolor", setColor).Methods("POST")

	log.Fatal(http.ListenAndServe(":8080", r))
}
