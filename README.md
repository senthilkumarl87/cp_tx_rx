# CP TX/RX - Custom Protocol Transmitter/Receiver

A C++ implementation of a custom protocol for packet transmission and reception with XML-based configuration. This project provides a flexible framework for defining custom packet structures and handling communication between transmitter and receiver.

## Features

- XML-based packet configuration
- Custom header and message structures
- Support for variable-length fields
- Action-based packet handling
- Binary data transmission
- Configurable packetization

## Project Structure

```
.
├── acnUtil.[cc/h]      # Action utilities and function handling
├── bitConfig.[cc/h]    # Bit manipulation utilities
├── cp_tx_rx.cbp        # Code::Blocks project file
├── linkUtils.[cc/h]    # Link layer utilities
├── main.cpp           # Main application entry point
├── packet.xml         # Example packet configuration
├── rxUtils.[cc/h]     # Receiver utilities
├── struct_classes.h   # Data structures
├── txUtils.[cc/h]     # Transmitter utilities
└── xmlConfig.[cc/h]   # XML configuration parser
```

## XML Configuration

Define your packet structure in an XML file (e.g., `packet.xml`):

```xml
<packet>
    <header name="header_name" 
            numfields="5" 
            acnField="Field2"
            acnValue="2" 
            acnFnId="eu352n">
        <Field name="Field1" size="16">1101001010111100</Field>
        <Field name="Field2" size="2">10</Field>
        <Field name="Field3" size="1">1</Field>
        <Field name="Field4" size="32">11010010101111001101001010111100</Field>
        <Field name="Field5" size="64">1101001010111100110100101011110011010010101111001101001010111100</Field>
    </header>
    <message name="message_name" 
             numfields="1" 
             payLoadSize="85">
        <Field name="Field1" size="8">ctext1</Field>
    </message>
</packet>
```

### XML Schema

- **`<packet>`**: Root element
  - **`<header>`**: Defines the packet header
    - `name`: Header name
    - `numfields`: Number of fields in the header
    - `acnField`: Field name that triggers an action
    - `acnValue`: Value that triggers the action
    - `acnFnId`: Action function identifier
    - **`<Field>`**: Header field definition
      - `name`: Field name
      - `size`: Field size in bits
  - **`<message>`**: Defines the message payload
    - `name`: Message name
    - `numfields`: Number of fields in the message
    - `payLoadSize`: Total payload size in bits
    - **`<Field>`**: Message field definition
      - `name`: Field name
      - `size`: Field size in bits

## Building the Project

1. Ensure you have a C++ compiler (g++ or compatible) and make installed
2. Clone the repository
3. Build using Code::Blocks or your preferred build system

## Usage

1. **Configure** your packet structure in `packet.xml`
2. **Implement** action functions in `acnUtil.cc` if needed
3. **Run** the application:
   ```
   ./cp_tx_rx
   ```
4. The application will process the input string and generate packets according to the XML configuration

## Adding Custom Actions

To add custom actions:

1. Open `acnUtil.cc`
2. Locate the `mainFn` function
3. Add a new case in the switch statement for your action value:
   ```cpp
   case YOUR_ACTION_VALUE:
       // Your action code here
       break;
   ```

## Data Flow

1. Input string is processed by the application
2. Based on XML configuration, the input is packetized
3. Each packet contains a header and message payload
4. The transmitter (`txUtils`) handles packet creation
5. The receiver (`rxUtils`) handles packet processing
6. Action functions are triggered based on header field values

## License

[Specify your license here]

## Contributing

Contributions are welcome! Please submit a pull request or open an issue to discuss your ideas.
