# Standard Libraries

import json
from six.moves.urllib.request import urlopen

# My Libraries

# Code Below  

def GetDatatypes():
    
    url = "http://census.daybreakgames.com/s:mozrin/json/get/eq2/"

    raw = urlopen(url)
    content = raw.read()
    
    print(content)
    
    #json_datatypes = json.loads(content)
    
    #print(json_datatypes['returned'])