package main

import (
	"encoding/json"
	"log"
	"net/http"

	"github.com/gorilla/mux"
	"github.com/tarm/serial"
)

type ledState struct {
	COLORS []int `json:"colors,omitempty"`
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

	ser.Write([]byte("^"))

	for i := 0; i < len(led.COLORS); i++ {

		//val := fmt.Sprintf("%x", led.COLORS[i])

		_, err := ser.Write([]byte(led.COLORS[i]))
		if err != nil {
			log.Fatal(err)
		}
	}

	ser.Write([]byte("$00"))

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
