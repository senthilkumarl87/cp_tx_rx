# cp_tx_rx
 1. Create an xml file
 2. XML format:

 <packet>
<header name="<header name>" numfields = "<number of fields in header>" acnField="Field name of action"  acnValue="<Value to trigger the action function>" acnFnId="eu352n">
    <Field name="<Field name>" size = "Field size in bits"></Field>
    -----------------------------------------
</header>
<message name="<message name>" numfields = "1" payLoadSize = "<Message payload size in bits>">
</message>
</packet>

3.In the acnUtils.cc file look in to the switch condition in mainFn, add switch value as action Value to trigger the action function which was mentioned in xml file.

4. Feed the input, for any input the number of packet will generated based on the xml parameters. Packet information will be stored in txStream structure.

5. In the txStream structure tx8bitBuffer field contains the transmit buffer. Use this buffer for transmission.

6. Once receiver gathered the packet, it can extract header and message seperatly and store it in txStream structure.

7. In the receiver side you can decode the binary back to the input format , based on the action field in the xml, action function can be executed.

8. Header information is available in the txStream can be used to assist the action function.
