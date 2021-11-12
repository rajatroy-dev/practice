package in.rajatroy.rolebasedauthentication.security;

import static in.rajatroy.rolebasedauthentication.security.ApplicationUserRole.*;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.security.provisioning.InMemoryUserDetailsManager;

@Configuration
@EnableWebSecurity
public class ApplicationSecurityConfig extends WebSecurityConfigurerAdapter {
	
	private final PasswordEncoder passwordEncoder;
	
	@Autowired
	public ApplicationSecurityConfig(PasswordEncoder passwordEncoder) {
		this.passwordEncoder = passwordEncoder;
	}

	@Override
	protected void configure(HttpSecurity http) throws Exception {
		http
			.authorizeRequests()
			.antMatchers("/home")
			.permitAll()
			.antMatchers("/api/**")
			.hasAnyRole(STUDENT.name())
			.anyRequest()
			.authenticated()
			.and()
			.httpBasic();
	}

	@Override
	@Bean
	protected UserDetailsService userDetailsService() {
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
		
		return new InMemoryUserDetailsManager(admin, student);
	}

}
