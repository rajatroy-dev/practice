import { Link, Route, Switch, useParams } from "react-router-dom";

const Home = () => {
  const { name } = useParams();
  return <p>Hi! {name}</p>;
}

function App() {
  return (
    <>
      <ul>
        <li>
          <Link to="/home/Anthony">Anthony</Link>
        </li>
        <li>
          <Link to="/home/Bella">Bella</Link>
        </li>
        <li>
          <Link to="/home/Chrisite">Christie</Link>
        </li>
      </ul>

      <Switch>
        <Route path="/home/:name">
          <Home />
        </Route>
      </Switch>

    </>
  );
}

export default App;
