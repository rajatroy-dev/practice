# USER ROLES AND PERMISSIONS (AUTHORITIES) - PERMISSION-BASED AUTHENTICATION
   
*A user should have roles and permissions.*

*Permission / authority - represents a low-level, granular permission / authority in the system.*

*Role - this represents the high-level roles of the user in the system; each role will have a set of low-level privileges. A role may 0 or more permissions.*

1. Go to [spring initializr](https://start.spring.io/).
2. Select **Project** (Here we will choose `Maven`).
3. Select **Language** (Here we will choose `Java`).
4. Select **Spring Boot** version (Here we will choose `2.5.6`).
5. Provide **Project Metadata** details:
   1. **Group** (Here we will enter `in.rajatroy`).
   2. **Artifact** (Here we will enter `permissionbasedauthentication`).
   3. **Name** (auto-filled).
   4. **Description** (Here we will enter `User roles and permissions (permission-based authentication) in Spring Boot using Spring Security`).
   5. **Package name** (auto-filled).
   6. **Packaging** (Here we choose `Jar`).
   7. **Java** (Here we choose `11`).
6. **Dependencies** (Here we add the following):
   1. **Spring Security**
   2. **Spring Web**
7. Click on **Generate**.
8.  Extract the downloaded zip.
9.  Open up the extracted folder in your IDE.
10. Create `model` package inside `src/main/java/in.rajatroy/permissionbasedauthentication` package.
11. Inside `model` package, create `Student` class.
12. Add two properties, **id** and **name** to `Student` class and add their corresponding **getters**, **setters** and **contructor**.
13. Inside `src/main/java/in.rajatroy/permissionbasedauthentication` package create `controller` package.
14. Inside, `controller` package, create `HomeController.java` file.
15. Annotate `HomeController` with `@RestController` and `@RequestMapping("")`.
16. Create method for `GET` as a dummy.
17. Annotate `GET` method with `@GetMapping("/home")`.
18. Inside, `controller` package, create `StudentController.java` file.
19. Annotate `StudentController` with `@RestController` and `@RequestMapping("api/v1/student")`.
20. Create a constant list of students as a temporary database inside `StudentController`.
21. Create method for `GET` student.
22. Annotate `GET` method with `@GetMapping("/{id}")`.
23. Inside, `controller` package, create `StudentManagementController.java` file.
24. Annotate `StudentManagementController` with `@RestController` and `@RequestMapping("management/api/v1/student")`.
25. Create a constant list of students as a temporary database inside `StudentManagementController`.
26. Create method for `GET` student.
27. Annotate `GET` method with `@GetMapping("/{id}")`.
28. Create method for `GET` all students.
29. Annotate `GET` method with `@GetMapping("")`.
30. Create method for `POST` to create a new student with dummy body.
31. Annotate `POST` method with `@PostMapping("")`.
32. Create method for `DELETE` to delete a student with dummy body.
33. Annotate `DELETE` method with `@DeleteMapping("/{id}")`.
34. Create method for `PUT` to update an existing student with dummy body.
35. Annotate `PUT` method with `@PutMapping("")`.
36. Create a `security` package under `src/main/java/in.rajatroy/permissionbasedauthentication`.
37. Inside `security` package, create `ApplicationSecurityConfig.java` file.
38. Annotate `ApplicationSecurityConfig` class with `@Configuration` and `@EnableWebSecurity`.
39. `ApplicationSecurityConfig` class needs to extend `WebSecurityConfigurerAdapter`.
40. For encrypting password, create a `PasswordConfig.java` file inside `security` package.
41. Add `@Configuration` tag to `PasswordConfig` class.
42. Add the following method to `PasswordConfig` class:

         @Bean
         public PasswordEncoder passwordEncoder() {
            return new BCryptPasswordEncoder(10); // 10 is the strength
         }

43. `passwordEncoder` returns `PasswordEncoder`. So, when we look at the implmentations of `PasswordEncoder`, we get `BCryptPasswordEncoder` class that implements all the methods of `PasswordEncoder`.
44. In `ApplicationSecurityConfig` class, create a private final variable for `PasswordEncoder`.
45. `ApplicationSecurityConfig` has to `@Autowired` with `PasswordEncoder` as argument.
47. In `security` package, create `ApplicationUserPermission` enum in file `ApplicationUserPermission.java`.
48. Add the following to `ApplicationUserPermission` enum:

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

49. Add a new dependency in `pom.xml`:

         <dependency>
            <groupId>com.google.guava</groupId>
            <artifactId>guava</artifactId>
            <version>31.0.1-jre</version>
         </dependency>

50. In `security` package, create `ApplicationUserRole` enum in file `ApplicationUserRole.java`.
51. Add the following to `ApplicationUserRole` enum:

         STUDENT(Sets.newHashSet()),
         ADMIN(Sets.newHashSet(COURSE_READ, COURSE_WRITE, STUDENT_WRITE, STUDENT_READ)),
         ADMINTRAINEE(Sets.newHashSet(COURSE_READ, STUDENT_READ));

         private final Set<ApplicationUserRole> permissions;

         ApplicationUserRole(Set<ApplicationUserRole> permissions) {
            this.permissions = permissions;
         }

         public Set<ApplicationUserRole> getPermissions() {
            return permissions;
         }

         public Set<SimpleGrantedAuthority> getGrantedAuthorites() {
            Set<SimpleGrantedAuthority> permissions = getPermissions().stream()
                     .map(permission -> new SimpleGrantedAuthority(permission.getPermission()))
                     .collect(Collectors.toSet());

            permissions.add(new SimpleGrantedAuthority("ROLE_" + this.name()));

            return permissions;
         }

52. If we take a look at the implementations of `GrantedAuthority`, we find `SimpleGrantedAuthority`.
53. In `ApplicationSecurityConfig` class, override `userDetailsService()` method and add `@Bean` tag. When we use `@Bean` tag for a method in `@Configuration` tagged class, the method is available in the whole applicaiton context (get a fully initialized instance) and can be `@Autowired`.
54. To create users, we need to keep in mind that a user needs to have the following properties: `username`, `password` (must be encoded), `ROLE_NAME` (roles).
55. Add the following users in `userDetailsService()` method as follows:

         UserDetails admin = User.builder()
                                 .username("admin")
                                 .password(passwordEncoder.encode("password"))
                                 .authorities(ADMIN.getGrantedAuthorities())
                                 .build();

         UserDetails student = User.builder()
                                 .username("student")
                                 .password(passwordEncoder.encode("password"))
                                 .authorities(STUDENT.getGrantedAuthorities())
                                 .build();

         UserDetails admintrainee = User.builder()
                                 .username("admintrainee")
                                 .password(passwordEncoder.encode("password"))
                                 .authorities(ADMINTRAINEE.getGrantedAuthorities())
                                 .build();

         return new InMemoryUserDetailsManager(
            admin,
            student,
            admintrainee
         );

56. If we look at the implementation of `User.builder().roles(...)`, we will see that it returns a list of `SimpleGrantedAuthority`. `SimpleGrantedAuthority` constructor takes a string as argument and prepends `ROLE_` to that string. Thus, `ROLE_STUDENT`, etc.
57. `userDetailsService()` returns `UserDetailsService`. So, when we look at the implementations of `UserDetailsService`, we get `InMemoryUserDetailsManager` class that uses in-memory database for working with users.
58. In `ApplicationSecurityConfig` class, override `configure(HttpSecurity http)` method.
59. We are trying to configure the security for "home" endpoint and the rest of the api(s) seperately, so that, all users can access the "home" endpoint but only authorized users can access rest of the api(s).
60. Inside `configure(HttpSecurity http)`, remove existing statements and add the following:

         http
            .csrf()
            .disable()
            .authorizeRequests()
            .antMatchers("/home")
            .permitAll()
            .antMatchers("/api/**")
            .hasRole(STUDENT.name())
            .anyRequest()
            .authenticated()
            .and()
            .httpBasic();

61. Annotate `ApplicationSecurityConfig` class with `@EnableGlobalMethodSecurity(prePostEnabled = true)`
62. In `StudentManagementController` class, annotate `GET` all students method with `@PreAuthorize("hasAnyRole('ROLE_ADMIN', 'ROLE_ADMINTRAINEE')")`.

      > `@PreAuthorize` accepts these values as argument: `hasRole("ROLE_")`, `hasAnyRole("ROLE_")`, `hasAuthority("permission")` and `hasAnyAuthority("permission")`.

63. Annotate `PUT` method for updating an existing student with `@PreAuthorize("hasAuthority('student:write')")`.
64. Annotate `DELETE` method for deleting an existing student with `@PreAuthorize("hasAuthority('student:write')")`.
65. Annotate `POST` method for create a new student with `@PreAuthorize("hasAuthority('student:write')")`.
66. Run the project.