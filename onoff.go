package main

import (
	"encoding/json"
	"log"
	"net/http"

	"github.com/gorilla/mux"
	"github.com/tarm/serial"
)

// Saves the state of the LED as a string. 1 is on, 0 is off.
type State struct {
	STATE string `json:"state,omitempty"`
}

// Stores the state of the LED at all times
var led []State

// Starts new serial port and opens it
var c = &serial.Config{Name: "COM4", Baud: 115200}
var ser, _ = serial.OpenPort(c)

// Returns the state of the LED
func GetState(w http.ResponseWriter, req *http.Request) {
	json.NewEncoder(w).Encode(led)
}

// Acts as a light switch for the LED. Pass in state as 1 to turn on, 0 to turn off
func OnOff(w http.ResponseWriter, req *http.Request) {
	params := mux.Vars(req)

	// Sets the state of the LED to the requested state (params["state"])
	_, err := ser.Write([]byte(params["state"]))
	if err != nil {
		log.Fatal(err)
	}

	var newLed State
	//_ = json.NewDecoder(req.Body).Decode(&newLed)
	newLed.STATE = params["state"]

	led = append(led[:0], newLed)

	json.NewEncoder(w).Encode(led)
}

func main() {
	r := mux.NewRouter()

	// Initializes the LED as off
	led = append(led, State{STATE: "0"})

	_, err := ser.Write([]byte("0"))
	if err != nil {
		log.Fatal(err)
	}

	r.HandleFunc("/switch", GetState).Methods("GET")
	r.HandleFunc("/switch/{state}", OnOff).Methods("POST")

	log.Fatal(http.ListenAndServe(":8080", r))
}
