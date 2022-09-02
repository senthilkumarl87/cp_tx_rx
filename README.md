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

4. Feed the input, for any input the number of packet will change based on the xml parameters.

5. In the receiver side you can decode the binary back to the input
