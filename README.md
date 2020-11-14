# Logger

A lightweight and colourful logger for C++ programs with functionality for logging to files.

## Installation

You can use either the batch files to either compile to DLL or a static library, you could also simply include the source files.

## Usage

```cpp
#include "src/Logger.h"

int main() {
    hxz::Logger log = hxz::Logger(HXZ_LOGGER_DATETIME);
    log.Info("Info text");
    log.Debug("Debug text");
    log.Warn("Warn text");
    log.Success("Success text");
    log.Error("Error text");

    return 0;
}
```

![](https://i.imgur.com/1jicPO6.png)

### Logger parameters

When constructing the logger, you are able to pass in the format of the date/time displayed, as well as whether you want to log to a file and the path of the log folder. By default file logging is disabled and the log path is set to ".\log".

The three date/time formats are as so:

![](https://i.imgur.com/KS2HRvn.png)

![](https://i.imgur.com/gfw4Tfq.png)

![](https://i.imgur.com/P4qcXiO.png)

## License
[MIT](https://choosealicense.com/licenses/mit/)