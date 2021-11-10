# ANTMATCHER USING SPRING SECURITY
   
*Allows configuring the HttpSecurity to only be invoked when matching the provided ant pattern.*

1. Go to [spring initializr](https://start.spring.io/).
2. Select **Project** (Here we will choose `Maven`).
3. Select **Language** (Here we will choose `Java`).
4. Select **Spring Boot** version (Here we will choose `2.5.6`).
5. Provide **Project Metadata** details:
   1. **Group** (Here we will enter `in.rajatroy`).
   2. **Artifact** (Here we will enter `antmatcher`).
   3. **Name** (auto-filled).
   4. **Description** (Here we will enter `Antmatcher in Spring Boot using Spring Security`).
   5. **Package name** (auto-filled).
   6. **Packaging** (Here we choose `Jar`).
   7. **Java** (Here we choose `11`).
6. **Dependencies** (Here we add the following):
   1. **Spring Security**
   2. **Spring Web**
7. Click on **Generate**.
8.  Extract the downloaded zip.
9.  Open up the extracted folder in your IDE.
10. Create `model` package inside `src/main/java/in.rajatroy/antmatcher` package.
11. Inside `model` package, create `Student` class.
12. Add two properties, **id** and **name** to `Student` class and add their corresponding **getters**, **setters** and **contructor**.
13. Inside `src/main/java/in.rajatroy/antmatcher` package create `controller` package.
14. Inside, `controller` package, create `HomeController.java` file.
15. Annotate `HomeController` with `@RestController` and `@RequestMapping("")`.
16. Create method for `GET` as a dummy.
17. Annotate `GET` method with `@GetMapping(/home)`.
18. Inside, `controller` package, create `StudentController.java` file.
19. Annotate `StudentController` with `@RestController` and `@RequestMapping("api/v1/students")`.
20. Create a constant list of students as a temporary database inside `StudentController`.
21. Create method for `GET` student.
22. Annotate `GET` method with `@GetMapping(/{id})`.
23. Create a `security` package under `src/main/java/in.rajatroy/antmatcher`.
24. Inside `security` package, create `ApplicationSecurityConfig.java` file.
25. Annotate `ApplicationSecurityConfig` class with `@Configuration` and `@EnableWebSecurity`.
26. `ApplicationSecurityConfig` class needs to extend `WebSecurityConfigurerAdapter`.
27. In `ApplicationSecurityConfig` class, override `configure(HttpSecurity http)` method.
28. We are trying to configure the security for "home" endpoint and the rest of the api(s) seperately, so that, all users can access the "home" endpoint but only authorized users can access rest of the api(s).
29. Inside `configure(HttpSecurity http)`, remove existing statements and add the following:

         http
            .authorizeRequests()
            .antMatchers("/home")
            .permitAll()
            .anyRequest()
            .authenticated()
            .and()
            .httpBasic();

30. Run the project.
31. Username is **"user"**.
32. Use password from console.