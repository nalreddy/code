import gdb

class SimpleCommand(gdb.Command):
    def __init__(self):
# This registers our class as "simple_command"
        super(SimpleCommand, self).__init__("simple_command", gdb.COMMAND_DATA)

        def invoke(self, arg, from_tty):
# When we call "simple_command" from gdb, this is the method
# that will be called.
            print("Hello from simple_command!")

# This registers our class to the gdb runtime at "source" time.
SimpleCommand()
