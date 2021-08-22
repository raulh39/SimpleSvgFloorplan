# Simple SVG Floorplan
I am not a graphic designer... at all.
But I always end up making ugly sketches of the different rooms in my house when we want to get into construction or buy furniture.
And guess what, I'm a programmer, so there should be a better way.

The other day I had an idea. When I measure my rooms I take notes in the form "that wall has 130cm, then turns right 90 degrees, then another 35cm wall, a door of 90cm..."

So, what if I made a program that translates those instructions into a graphic? Wouldn't be it awesome?

Well, if I remember correctly, in the past none of my ideas ended well. They didn't even end up going anywhere, so I don't know why this one will be any different. But, hey, just try to make it for the fun of it!

## SVG
Why to use that graphic format?

Well, I could tease you by saying a lot of advantages that have occurred to me with hindsight, but the real truth is that I'm going to use this format because it's the easiest one to test with.

My plan is that the code generates strings representing SVG files (SVG is xml) that can be easely compared with the expected ones.

Maybe I can even use some XML library (or SVG) but right now I want to keep it simple.

## Input format
So, what is the input format I want to create?
Well, I don't know. But as I have ot start with something, I will start with TDD as see how it goes.
