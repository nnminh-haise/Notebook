
# Introduction To Spring

> This note will cover why and the beneficial of using Spring

---

## The Benefits And Downsides Of Using Frameworks

### The Benefits

- Help users focusing on the task rather than the boilerplate stuff.
- Ensure the code base follow a design pattern.
- Lower the cost of ownership for the application.
- Create & follow a standard of the industry.

### The Downsides

- Force the users to follow a specific manner why programming.
- Bind to a specific version of language and libraries.
- Adds to the resource footprint of the application. (still dunno what this means)

---

## The Spring Framework

Spring framework is divided into modules which makes it really easy to pick and choose in parts to use in any application:

- Core: Provides core features like DI (Dependency Injection), Internationalisation, Validation, and AOP (Aspect Oriented Programming)
- Data Access: Supports data access through JTA (Java Transaction API), JPA (Java Persistence API), and JDBC (Java Database Connectivity)
- Web: Supports both Servlet API (Spring MVC) and of recently Reactive API (Spring WebFlux), and additionally supports WebSockets, STOMP, and WebClient
- Integration: Supports integration to Enterprise Java through JMS (Java Message Service), JMX (Java Management Extension), and RMI (Remote Method Invocation)
- Testing: Wide support for unit and integration testing through Mock Objects, Test Fixtures, Context Management, and Caching
