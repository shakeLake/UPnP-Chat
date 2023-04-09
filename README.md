# UPnP Chat

**UPnP Chat** makes peer-to-peer connection between two computers

![image](https://user-images.githubusercontent.com/99725123/230795307-2b1e081d-2aa9-4325-ae0d-04c25fab71b8.png)

**UPnP Chat** uses [miniupnp](https://github.com/miniupnp/miniupnp) to opens port

## How To Use

### Computer as Server
* Turn on **UPnP** and **NAT Traversal** on your router
* Click **UPnP button** and enter **the Port** you need in dialog window
* Wait **the Client**
<details>
    <summary>Screenshot</summary>
    <img src="https://user-images.githubusercontent.com/99725123/230796605-ee5fc252-29b0-4f1d-b96a-d4329d48972e.png"/>
</details>

### Computer as Client 
* Click **Connect button**
* Enter **Server Ip** and **Server Port** 
<details>
    <summary>Screenshot</summary>
    <img src="https://user-images.githubusercontent.com/99725123/230796588-77cb8035-e45f-4273-b9bc-cf7dcb896e6e.png"/>
</details>

### Router Doesn't Support UPnP
* Click **NAT button** and enter **opened port** on your router
* Wait **the Client**

## Third Party
* Qt 6 
* Standalone Asio
* miniupnp
* CMake

## How To Build

* Download **CMake 3.2 and later** from https://cmake.org/download/
* Download **Git** from https://git-scm.com/downloads

#### Clone project
```
git clone https://github.com/shakeLake/UPnP-Chat.git
```

#### Build project
```
~/UPnP-Chat/build-release.sh
```
