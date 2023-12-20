from tqdm import tqdm
from tqdm import trange

# case 1: Using an list(integer or string)
for i in tqdm(range(1000)):
     #do something
     pass

# case 2: Using trange
# trange(i) 是 tqdm(range(i)) 的简单写法
for i in trange(100):
    #do something
    a=1
    pass

# case 3: By manually.
bar = tqdm(["a", "b", "c", "d"],bar_format="{l_bar}{bar}")
for char in bar:
    # bar.set_description("Processing %s" % char)
    pass