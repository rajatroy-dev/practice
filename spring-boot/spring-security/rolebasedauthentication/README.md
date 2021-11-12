# USER ROLES AND PERMISSIONS (AUTHORITIES) - ROLE-BASED AUTHENTICATION
   
*A user should have roles and permissions.*

*Permission / authority - represents a low-level, granular permission / authority in the system.*

*Role - this represents the high-level roles of the user in the system; each role will have a set of low-level privileges. A role may 0 or more permissions.*

1. Go to [spring initializr](https://start.spring.io/).
2. Select **Project** (Here we will choose `Maven`).
3. Select **Language** (Here we will choose `Java`).
4. Select **Spring Boot** version (Here we will choose `2.5.6`).
5. Provide **Project Metadata** details:
   1. **Group** (Here we will enter `in.rajatroy`).
   2. **Artifact** (Here we will enter `rolebasedauthentication`).
   3. **Name** (auto-filled).
   4. **Description** (Here we will enter `User roles and permissions (role-based authentication) in Spring Boot using Spring Security`).
   5. **Package name** (auto-filled).
   6. **Packaging** (Here we choose `Jar`).
   7. **Java** (Here we choose `11`).
6. **Dependencies** (Here we add the following):
   1. **Spring Security**
   2. **Spring Web**
7. Click on **Generate**.
8.  Extract the downloaded zip.
9.  Open up the extracted folder in your IDE.
10. Create `model` package inside `src/main/java/in.rajatroy/rolebasedauthentication` package.
11. Inside `model` package, create `Student` class.
12. Add two properties, **id** and **name** to `Student` class and add their corresponding **getters**, **setters** and **contructor**.
13. Inside `src/main/java/in.rajatroy/rolebasedauthentication` package create `controller` package.
14. Inside, `controller` package, create `HomeController.java` file.
15. Annotate `HomeController` with `@RestController` and `@RequestMapping("")`.
16. Create method for `GET` as a dummy.
17. Annotate `GET` method with `@GetMapping(/home)`.
18. Inside, `controller` package, create `StudentController.java` file.
19. Annotate `StudentController` with `@RestController` and `@RequestMapping("api/v1/students")`.
20. Create a constant list of students as a temporary database inside `StudentController`.
21. Create method for `GET` student.
22. Annotate `GET` method with `@GetMapping(/{id})`.
23. Create a `security` package under `src/main/java/in.rajatroy/rolebasedauthentication`.
24. Inside `security` package, create `ApplicationSecurityConfig.java` file.
25. Annotate `ApplicationSecurityConfig` class with `@Configuration` and `@EnableWebSecurity`.
26. `ApplicationSecurityConfig` class needs to extend `WebSecurityConfigurerAdapter`.
27. To create users, we need to keep in mind that a user needs to have the following properties: `username`, `password` (must be encoded), `ROLE_NAME` (roles).
28. For encrypting password, create a `PasswordConfig.java` file inside `security` package.
29. Add `@Configuration` tag to `PasswordConfig` class.
30. Add the following method to `PasswordConfig` class:

         @Bean
         public PasswordEncoder passwordEncoder() {
            return new BCryptPasswordEncoder(10); // 10 is the strength
         }

31. `passwordEncoder` returns `PasswordEncoder`. So, when we look at the implmentations of `PasswordEncoder`, we get `BCryptPasswordEncoder` class that implements all the methods of `PasswordEncoder`.
32. In `ApplicationSecurityConfig` class, create a private final variable for `PasswordEncoder`.
36. `ApplicationSecurityConfig` has to `@Autowired` with `PasswordEncoder` as argument.
37. In `security` package, create `ApplicationUserPermission` enum in file `ApplicationUserPermission.java`.
38. Add the following to `ApplicationUserPermission` enum:

         STUDENT_WRITE("student:write"),
         STUDENT_READ("student:read"),
         COURSE_READ("course:read"),
         COURSE_WRITE("course:read")

         private final String permission;

         ApplicationUserPermission(String permission) {
            this.permission = permission;
         }

         public String getPermission() {
            return permission;
         }

39. Add a new dependency in `pom.xml`:

         <dependency>
            <groupId>com.google.guava</groupId>
            <artifactId>guava</artifactId>
            <version>31.0.1-jre</version>
         </dependency>

40. In `security` package, create `ApplicationUserRole` enum in file `ApplicationUserRole.java`.
41. Add the following to `ApplicationUserRole` enum:

         STUDENT(Sets.newHashSet()),
         ADMIN(Sets.newHashSet(COURSE_READ, COURSE_WRITE, STUDENT_WRITE, STUDENT_READ));

         private final Set<ApplicationUserRole> permissions;

         ApplicationUserRole(Set<ApplicationUserRole> permissions) {
            this.permissions = permissions;
         }

         public Set<ApplicationUserRole> getPermissions() {
            return permissions;
         }

42. In `ApplicationSecurityConfig` class, override `userDetailsService()` method and add `@Bean` tag. When we use `@Bean` tag for a method in `@Configuration` tagged class, the method is available in the whole applicaiton context (get a fully initialized instance) and can be `@Autowired`.
43. Add the following users in `userDetailsService()` method as follows:

         UserDetails admin = User.builder()
                                 .username("admin")
                                 .password(passwordEncoder.encode("password"))
                                 .roles(ADMIN.name()) // ROLE_ADMIN
                                 .build();

         UserDetails student = User.builder()
                                 .username("student")
                                 .password(passwordEncoder.encode("password"))
                                 .roles(STUDENT.name()) // ROLE_STUDENT
                                 .build();

         return new InMemoryUserDetailsManager(
            admin,
            student
         );

44. `userDetailsService()` returns `UserDetailsService`. So, when we look at the implementations of `UserDetailsService`, we get `InMemoryUserDetailsManager` class that uses in-memory database for working with users.
45. In `ApplicationSecurityConfig` class, override `configure(HttpSecurity http)` method.
46. We are trying to configure the security for "home" endpoint and the rest of the api(s) seperately, so that, all users can access the "home" endpoint but only authorized users can access rest of the api(s).
47. Inside `configure(HttpSecurity http)`, remove existing statements and add the following:

         http
            .authorizeRequests()
            .antMatchers("/home")
            .permitAll()
            .antMatchers("/api/**")
            .hasRole(STUDENT.name())
            .anyRequest()
            .authenticated()
            .and()
            .httpBasic();

48. Run the project.