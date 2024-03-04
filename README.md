Sc_module(name) 
Sc_in<>input;
Sc_out<>output;

Sc_signal<>h1; // here define as many helping signals as you want

Sc_ctor(name)
Sc_method(process1);
Sensitive << clk.pos() <<  reset;
Sc_method(process2);
Sensitive << h1 …..;


Void (process1) //combinational 
Output = h1 + ……


Void (process2)
If (reset)
h1 = 0 //output of each register goes to 0

Else if (clock edge)
h1 = input // all outputs of the registers equal to the inputs
…..


---------------------------------------------///SystemC Basics///-------------------------------------------------------------

TOPICS DISCUSSED: SC_MODULE, SC_CTOR, delta delay (enables the simulation of concurrency in a sequential simulator), stages of SystemC Simulation Kernel, SC_METHOD, SC_THREAD, sc_event, sc_time, dynamic sensitivity

 --For combinational logic or processes that do not need to maintain state, SC_METHOD is typically used. For sequential logic or processes that need to wait for events, SC_THREAD is typically used
 --No wait() statements with SC_METHOD - will crash simulation
 --In SystemC, SC_THREAD processes do not require a sensitivity list because they are designed to be self-scheduling. This means that they control their own execution using wait() statements.
 --SC_METHOD processes are event-driven and use a sensitivity list to specify which events will trigger them.
 
 --Events are caused or fired through the event class member function notify(): - should ideally be done with a time argument 
 --in case of multiple notifications, only the first one is noted, rest are ignored
 --to trigger events more than once, sc_event can't be used, sc_event_queue has to be used

 --wait() statements in SC_THREAD are examples of dynamic sensitivity

-- WE CAN’T BIND PORTS TO PORTS DIRECTLY!! this will lead to problems that we will see in the next lecture - signals are required to interact with SystemC Kernel - at the edges, bindings are allowed without a signal as well because these are special ports that themselves act as signals


RELEVANT EXAMPLES: delta_delay, feedback_loop, swapping_example, thread_example, sc_event_and_queue, clock_generator, not_chain


--------------------------------------------///SystemC Advanced///--------------------------------------------------------------


TOPICS DISCUSSED: data types, and_reduce() methods, Channels, Interfaces, Primitive Channel  - {FIFO, Buffer, Signal}, Dynamic Processes, Report Handling, Callbacks

--signal is special case of Channel - Channels are containers for communication protocols
--Interface defines channel behaviour, Channel implements one or more interfaces
--Specialized Ports such as sc_in, sc_out, sc_inout are used for sc_signal, for RTL modelling and easy use
--sc_signal is a special type of channel - so are sc_fifo and sc_buffer, both being special cases of sc_signal which implement notifications, along with read and write

--signals can be exchanged with a FIFO or a Buffer - because the interface of all these signals and FIFOs is the same, we can interchange the communication models - an example of this is to put in a Ethernet Network or CAN bus or SPI Bus or I2C - modules do not know which channel is there because they use the same interface for write and read
-- sc_in<int> foo; is short MACRO for sc_port< sc_signal_in_if<int> > Foo;
--sc_out<bool> bar; which is short MACRO for sc_port< sc_signal_inout_if<bool> > Bar;
--sc_port has the parameters - Interface (required), N (maximum number of channels to be bound - optional), Policy (optional)

--complex channels like FIFO can only be modeled using SC_THREADS because SC_METHODS can't be used for blocking processes - blocking functions call an internal wait(), which SC_METHOD can't allow (will result in runtime error)
--primitive channels in SystemC = sc_signal, sc_buffer, sc_fifo, sc_mutex, sc_semaphore
--making your own custom primitve channel --> see slide 33 or example 'custom_signal'

--Hierachical Channels (non-primitive, active) --> have logic + usual channel stuff (useful in buses like CAN which use Arbitration)

--sc_buffer:==> The difference to sc_signal is that with sc_buffer an event is generated each time the write() method is called.With sc_signal, an event is only generated if the old and the new value of the signal are different

--! Two Ports cannot be bound to the same channel - for signals and FIFOs in example ‘portarrays’ - doing so gives an error - sc_fifo<T> cannot have more than one writer
--In SystemC, the order of execution of processes within the same delta cycle is not deterministic.
--If ports are created dynamically, use port.size() within module's process function to work on inidividual ports iteratively

--4 kinds of callbacks for sc_module, sc_prim_channel, sc_port and sc_export - see slide 53
◼ before_end_of_elaboration()
◼ end_of_elaboration()
◼ start_of_simulation()
◼ end_of_simulation()

RELEVANT EXAMPLES: custom_fifo, fifo_example, kpn_example, mutex_example, custom_signal, portarrays, multiports, sc_event_and_queue, event_finder, dynamic_processes, reporting, callbacks

sc_signal_in_if: This interface is used for input ports that receive signals.
sc_signal_out_if: This interface is used for output ports that send signals.
sc_fifo_in_if and sc_fifo_out_if: These interfaces are used for input and output ports respectively in FIFO (First-In-First-Out) communication channels.
